
struct HuffmanNode {
    int weight;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(int w) : weight(w), left(nullptr), right(nullptr) {}
};
