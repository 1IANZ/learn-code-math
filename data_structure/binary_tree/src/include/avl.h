#pragma once
#include "tree_node.h"

class AvlTree {
  private:
    TreeNode* root;
    void destroy(TreeNode* node);
    int height(TreeNode* node);
    int getBalance(TreeNode* node);
    TreeNode* rightRotate(TreeNode* y);
    TreeNode* leftRotate(TreeNode* y);
    TreeNode* insertNode(TreeNode* node, int value);
    TreeNode* removeNode(TreeNode* node, int value);
    void preorder(TreeNode* node);
    void inorder(TreeNode* node);
    void postorder(TreeNode* node);
    TreeNode* minValueNode(TreeNode* node);
    int size(TreeNode* node);

  public:
    AvlTree();
    ~AvlTree();
    bool insert(int value);
    bool remove(int value);
    bool find(int value);
    void preorder();
    void inorder();
    void postorder();
    int height();
    int size();
    int getMin();
    int getMax();
    static void test();
};
