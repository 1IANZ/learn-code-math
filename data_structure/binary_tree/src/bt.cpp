#include <stdlib.h>

#include "include/bt.h"
#include "include/tree_node.h"

BinaryTree::BinaryTree() { root = nullptr; }

BinaryTree::~BinaryTree() { destroy(root); }
void BinaryTree::destroy(TreeNode* node) {
    if (node == nullptr) return;
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
    TreeNode *current = root, *parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
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
    bool isLeftChild = true;
    while (current && current->value != value) {
        parent = current;
        if (value < current->value) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
    }
    if (!current) return false;
    // 无子节点
    if (!current->left && !current->right) {
        if (current == root) {
            root = nullptr;
        } else if (isLeftChild) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
        return true;
    }
    // 只有左子节点
    if (!current->right) {
        if (current == root) {
            root = current->left;
        } else if (isLeftChild) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        delete current;
        return true;
    }
    // 只有右子节点
    if (!current->left) {
        if (current == root) {
            root = current->right;
        } else if (isLeftChild) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        delete current;
        return true;
    }
    // 两个子节点
    if (current->left && current->right) {
        TreeNode* parentOfSuccessor = current;
        TreeNode* successor = current->right;
        while (successor->left != nullptr) {
            parentOfSuccessor = successor;
            successor = successor->left;
        }
        current->value = successor->value;
        if (parentOfSuccessor->left == successor) {
            parentOfSuccessor->left = successor->right;
        } else {
            parentOfSuccessor->right = successor->right;
        }
        delete successor;
        return true;
    }
    return false;
}
