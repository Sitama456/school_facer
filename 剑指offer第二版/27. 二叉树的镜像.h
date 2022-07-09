/**
 * @file 27. 二叉树的镜像.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 * 
 */
#include <algorithm>
#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        process(root);
        return root;
    }

    void process(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        std::swap(node->left, node->right);
        process(node->left);
        process(node->right);
    }
}; 