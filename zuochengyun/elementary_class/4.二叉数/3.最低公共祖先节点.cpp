/**
 * @file 3.最低公共祖先节点.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <map>
#include <queue>
using namespace std;


struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

/**
 * @brief o1 和 o2 一定属于head为头的树 返回 o1 和 o2 的最低公共祖先
 * 
 */
//1) o1 是 o2 的公共祖先 或者 o2 是 o1 的公共祖先
//2) o1 和 o2 的公共祖先是其他节点

TreeNode* lowstAncestor(TreeNode* head, TreeNode* o1, TreeNode* o2) {
    if (head == nullptr || head == o1 || head == o2) {
        return head;
    }

    TreeNode* left = lowstAncestor(head->left, o1, o2);
    TreeNode* right = lowstAncestor(head->right, o1, o2);
    if (left != nullptr && right != nullptr) {
        return head;
    }
    return left == nullptr ? right : left;

}



