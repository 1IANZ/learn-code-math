#include "include/bt.h"

#include "include/tree_node.h"
using namespace std;

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    destroy(root);
}
void BinaryTree::destroy(TreeNode* node) {
    if (!node)
        return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

bool BinaryTree::insert(E value) {
    TreeNode* newNode = new TreeNode(value);
    if (root == nullptr) {
        root = newNode;
        return true;
    }
    TreeNode* current = root;
    TreeNode* parent = nullptr;

    while (current) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else if (value > current->value) {
            current = current->right;
        } else {
            delete newNode;
            return false;
        }
    }

    if (value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    return true;
}

bool BinaryTree::remove(E value) {
    TreeNode* current = root;
    TreeNode* parent = nullptr;
    while (current && current->value != value) {
        parent = current;
        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if (!current)
        return false;

    // 节点有两个子节点
    if (current->left && current->right) {
        TreeNode* successor = current->right;
        TreeNode* successorParent = current;
        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }
        current->value = successor->value;
        current = successor;
        parent = successorParent;
    }

    // 只有一个子节点
    TreeNode* child = current->left ? current->left : current->right;

    if (!parent) {
        root = child;
    } else if (parent->left == current) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    delete current;
    return true;
}

bool BinaryTree::find(int value) {
    TreeNode* current = root;
    while (current) {
        if (current->value == value) {
            return true;
        } else if (current->value > value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}
void BinaryTree::preorder(TreeNode* node) {
    if (node == nullptr)
        return;
    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}
void BinaryTree::preorder() {
    preorder(root);
    cout << endl;
}
void BinaryTree::inorder(TreeNode* node) {
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}
void BinaryTree::inorder() {
    inorder(root);
    cout << endl;
}
void BinaryTree::postorder(TreeNode* node) {
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}
void BinaryTree::postorder() {
    postorder(root);
    cout << endl;
}
int BinaryTree::height(TreeNode* node) {
    if (!node)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}

int BinaryTree::height() {
    return height(root);
}
int BinaryTree::size(TreeNode* node) {
    if (!node)
        return 0;
    return size(node->left) + size(node->right) + 1;
}

int BinaryTree::size() {
    return size(root);
}

int BinaryTree::getMin() {
    if (!root)
        return -1;
    TreeNode* current = root;
    while (current->left)
        current = current->left;
    return current->value;
}

int BinaryTree::getMax() {
    if (!root)
        return -1;
    TreeNode* current = root;
    while (current->right)
        current = current->right;
    return current->value;
}
void BinaryTree::test() {
    BinaryTree bt;

    cout << "=== BinaryTree ===\n";
    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(3);
    bt.insert(7);
    bt.insert(12);
    bt.insert(18);

    cout << "preorder: ";
    bt.preorder();
    cout << "inorder: ";
    bt.inorder();
    cout << "postorder: ";
    bt.postorder();
    cout << "find(7): " << (bt.find(7) ? "Find" : "Not Find") << endl;
    cout << "find(20): " << (bt.find(20) ? "Find" : "Not Find") << endl;
    cout << "height = " << bt.height() << endl;
    cout << "size = " << bt.size() << endl;
    cout << "Min = " << bt.getMin() << endl;
    cout << "Max = " << bt.getMax() << endl;
    cout << "Delete 3 (leaf node):";
    bt.remove(3);
    bt.inorder();
    cout << "Delete 12 (node with one child):";
    bt.remove(12);
    bt.inorder();
    cout << "Delete 10 (node with two child):";
    bt.remove(10);
    bt.inorder();
    cout << "preorder: ";
    bt.preorder();
    cout << "inorder: ";
    bt.inorder();
    cout << "postorder: ";
    bt.postorder();
    cout << "height: " << bt.height() << endl;
    cout << "size: " << bt.size() << endl;
}
