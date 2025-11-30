#pragma once
#include "tree_node.h"
class BinaryTree {
   private:
    TreeNode* root;
    void destroy(TreeNode* node);
    void preorder(TreeNode* node);
    void inorder(TreeNode* node);
    void postorder(TreeNode* node);
    int height(TreeNode* node);
    int size(TreeNode* node);

   public:
    BinaryTree();
    ~BinaryTree();
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