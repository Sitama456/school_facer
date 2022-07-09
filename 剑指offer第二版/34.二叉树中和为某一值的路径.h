/**
 * @file 34.二叉树中和为某一值的路径.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> path;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        path.push_back(root->val);
        process(root, target - root->val, path, res);
        return res;
    }

    void process(TreeNode* node, int target, vector<int>& path, vector<vector<int>>& res) {
        if (!node->left && !node->right) {
            if (target == 0) {
                res.push_back(path);
            }
            return;
        }

        // 左边
        if (node->left) {
            path.push_back(node->left->val);
            process(node->left, target - node->left->val, path, res);
            path.pop_back();
        } 

        // 右边
        if (node->right) {
            path.push_back(node->right->val);
            process(node->right, target - node->right->val, path, res);
            path.pop_back();
        } 
    }
};