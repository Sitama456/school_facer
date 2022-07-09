/**
 * @file 54.二叉搜索树的第k大节点.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一棵二叉搜索树，请找出其中第 k 大的节点的值。
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
    // 右 中 左
    int kthLargest(TreeNode* root, int k) {
        process(root, k);
        return res;
    }

    void process(TreeNode* node, int& k) {
        if (node == NULL) {
            return;
        }
        process(node->right, k);
        k--;
        if (k == 0) res = node->val;
        process(node->left, k);
        
    }

private:
    int res = 0;
};