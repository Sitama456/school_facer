/**
 * @file 32.3. 从上到下打印二叉树.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
 * 
 */
#include <queue>
#include <vector>
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
        bool flag = false;
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
            if (flag) {
                reverse(tmp.begin(), tmp.end());
            }
            res.push_back(tmp);
            flag = !flag;
        }
        return res;
    }
};