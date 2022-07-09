/**
 * @file 55.2.平衡二叉树.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 * 
 */


#define NULL 0
#include <math.h>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        return height != -1;
    }

    int getHeight(TreeNode* node) {
        if (node == NULL) return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        if (abs(leftHeight - rightHeight) > 1 || leftHeight == -1 || rightHeight == -1) {
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }
};