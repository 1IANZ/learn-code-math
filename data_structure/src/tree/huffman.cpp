
#include "include/min_heap_huffman.h"

HuffmanTree::HuffmanTree() : root(nullptr) {}

HuffmanTree::~HuffmanTree() {
    destroy(root);
}
void HuffmanTree::destroy(HuffNode* node) {
    if (!node)
        return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

void HuffmanTree::build(const std::string& text) {
    if (text.empty())
        return;

    int freq[256] = {0};

    for (char c : text)
        freq[(unsigned char)c]++;

    MinHeapNode heap;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            heap.push(new HuffNode(i, freq[i]));
        }
    }

    while (heap.getSize() > 1) {
        HuffNode* a = heap.pop();
        HuffNode* b = heap.pop();
        HuffNode* merged = new HuffNode(a->freq + b->freq, a, b);
        heap.push(merged);
    }

    root = heap.pop();

    generateCodes(root, "");
}

void HuffmanTree::generateCodes(HuffNode* node, const std::string& prefix) {
    if (!node)
        return;

    if (!node->left && !node->right) {
        codes[(unsigned char)node->ch] = prefix;
        return;
    }

    generateCodes(node->left, prefix + "0");
    generateCodes(node->right, prefix + "1");
}

std::string* HuffmanTree::getCodesArray() {
    return codes;
}

void HuffmanTree::test() {
    std::string text = "abaac";
    std::cout << "Input text: " << text << "\n";
    HuffmanTree tree;
    tree.build(text);
    std::string* codes = tree.getCodesArray();
    std::cout << "Huffman Codes:\n";
    for (int i = 0; i < 256; i++) {
        if (!codes[i].empty()) {
            if (i >= 32 && i <= 126)
                std::cout << "  '" << (char)i << "' : " << codes[i] << "\n";
            else
                std::cout << "  [" << i << "] : " << codes[i] << "\n";
        }
    }
}
