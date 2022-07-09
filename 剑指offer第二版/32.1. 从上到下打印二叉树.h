/**
 * @file 32.1. 从上到下打印二叉树.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 * 
 */

#include <vector>
#include <queue>
using namespace std;
#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur = NULL;
        int size = 0;
        while (!q.empty()) {
            size = q.size();
            for (int i = 0; i < size; ++i) {
                cur = q.front();
                q.pop();
                res.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};