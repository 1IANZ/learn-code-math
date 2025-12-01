#pragma once
#include <iostream>
#define E int
class TreeNode {
  public:
    E value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};
