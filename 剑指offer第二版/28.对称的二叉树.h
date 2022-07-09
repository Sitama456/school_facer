/**
 * @file 28.对称的二叉树.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

    例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 */

#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return process(root->left, root->right);
    }

    bool process(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        if ((left == NULL && right) || (left && right == NULL)) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return process(left->left, right->right) && process(left->right, right->left);
    }
};