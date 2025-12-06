#include "include/avl.h"

#include <algorithm>

#include "include/tree_node.h"
using namespace std;

AvlTree::AvlTree() {
    root = nullptr;
}

AvlTree::~AvlTree() {
    destroy(root);
}
void AvlTree::destroy(TreeNode* node) {
    if (!node)
        return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
int AvlTree::height(TreeNode* node) {
    return node ? node->height : 0;
}
int AvlTree::getBalance(TreeNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}
TreeNode* AvlTree::minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}
// 右旋y,返回新的根x
TreeNode* AvlTree::rightRotate(TreeNode* y) {
    if (!y || !y->left)
        return y;
    TreeNode* x = y->left;
    TreeNode* t = x->right;
    x->right = y;
    y->left = t;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}
// 左旋x,返回新的根y
TreeNode* AvlTree::leftRotate(TreeNode* x) {
    if (!x || !x->right)
        return x;
    TreeNode* y = x->right;
    TreeNode* t = y->left;
    y->left = x;
    x->right = t;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
TreeNode* AvlTree::insertNode(TreeNode* node, int value) {
    if (!node)
        return new TreeNode(value);

    if (value < node->value)
        node->left = insertNode(node->left, value);
    else if (value > node->value)
        node->right = insertNode(node->right, value);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int bf = getBalance(node);
    // LL
    if (bf > 1 && value < node->left->value)
        return rightRotate(node);

    // RR
    if (bf < -1 && value > node->right->value)
        return leftRotate(node);

    // LR
    if (bf > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (bf < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
TreeNode* AvlTree::removeNode(TreeNode* node, int value) {
    if (!node)
        return nullptr;

    if (value < node->value)
        node->left = removeNode(node->left, value);
    else if (value > node->value)
        node->right = removeNode(node->right, value);
    else {
        if (!node->left || !node->right) {
            TreeNode* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            TreeNode* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = removeNode(node->right, temp->value);
        }
    }

    if (!node)
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int bf = getBalance(node);
    // LL
    if (bf > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    // LR
    if (bf > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RR
    if (bf < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    // RL
    if (bf < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
bool AvlTree::insert(int value) {
    if (find(value))
        return false;
    root = insertNode(root, value);
    return true;
}

bool AvlTree::remove(int value) {
    if (!find(value))
        return false;
    root = removeNode(root, value);
    return true;
}
void AvlTree::preorder(TreeNode* node) {
    if (!node)
        return;
    std::cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

void AvlTree::inorder(TreeNode* node) {
    if (!node)
        return;
    inorder(node->left);
    std::cout << node->value << " ";
    inorder(node->right);
}

void AvlTree::postorder(TreeNode* node) {
    if (!node)
        return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->value << " ";
}

void AvlTree::preorder() {
    preorder(root);
    std::cout << "\n";
}
void AvlTree::inorder() {
    inorder(root);
    std::cout << "\n";
}
void AvlTree::postorder() {
    postorder(root);
    std::cout << "\n";
}
bool AvlTree::find(int value) {
    TreeNode* cur = root;
    while (cur) {
        if (value == cur->value)
            return true;
        else if (value < cur->value)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return false;
}
int AvlTree::height() {
    return height(root);
}
int AvlTree::size(TreeNode* node) {
    if (!node)
        return 0;
    return 1 + size(node->left) + size(node->right);
}
int AvlTree::size() {
    return size(root);
}
int AvlTree::getMin() {
    TreeNode* cur = root;
    if (!cur)
        throw std::runtime_error("Tree is empty");
    while (cur->left)
        cur = cur->left;
    return cur->value;
}

int AvlTree::getMax() {
    TreeNode* cur = root;
    if (!cur)
        throw std::runtime_error("Tree is empty");
    while (cur->right)
        cur = cur->right;
    return cur->value;
}
void AvlTree::test() {
    AvlTree tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);
    tree.insert(35);
    tree.insert(50);

    std::cout << "Preorder: ";
    tree.preorder();
    std::cout << "Inorder: ";
    tree.inorder();
    std::cout << "Postorder: ";
    tree.postorder();

    std::cout << "Height: " << tree.height() << "\n";
    std::cout << "Size: " << tree.size() << "\n";
    std::cout << "Min: " << tree.getMin() << "\n";
    std::cout << "Max: " << tree.getMax() << "\n";

    tree.remove(20);
    std::cout << "After removing 20, Inorder: ";
    tree.inorder();
}
