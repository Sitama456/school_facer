/**
 * @file 2.7二叉树最大权值和.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 二叉树结点有一个权值 求二叉树根节点到叶节点的所有路径中的最大权值和
 * 
 */

#include <unistd.h>
#include <stdint.h>
#include <vector>
#include <math.h>
using namespace std;
#define INT_MIN pow(2, 31);
struct TreeNode
{
    int value = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int value) : value(value) { }
};

int maxValue = INT_MIN;

void maxSum(TreeNode* node, int pre) {
    if (node->left == nullptr && node->right == nullptr) {
        maxValue = max(maxValue, pre + node->value);
    }
    if (node->left) {
        maxSum(node->left, pre + node->value);
    }
    if (node->right) {
        maxSum(node->right, pre + node->value);
    }
}

/**
 * @brief 以node为根节点的最大路径返回
 * 
 * @param node 
 * @return int 
 */
int maxSum1(TreeNode* node) {
    if (node->left == nullptr && node->right == nullptr) {
        return node->value;
    }
    int next = INT32_MIN;
    if (node->left) {
        next = maxSum1(node->left);
    }
    if (node->right) {
        next = max(next, maxSum1(node->right));
    }
    return next;
}