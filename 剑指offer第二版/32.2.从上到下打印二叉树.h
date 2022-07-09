/**
 * @file 32.2.从上到下打印二叉树.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur = NULL;
        int size = 0;
        vector<int> tmp;
        while (!q.empty()) {
            tmp.clear();
            size = q.size();
            for (int i = 0; i < size; ++i) {
                cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};