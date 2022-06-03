/**
 * @file 2.判断二叉树属性.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <algorithm>
#include <stack>
#include <queue>
#include <unistd.h>
#include <math.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value = 0) : value(value), left(nullptr), right(nullptr) {}

};

// 搜索二叉树
/**
 * @brief 非递归版本判断是否为搜索二叉树
 * 
 * @param root 
 * @return true 
 * @return false 
 */
bool isSearchTreeNoRecur(TreeNode* root) {
    // 中序遍历
    if (root == nullptr) {
        return false;
    }
    int preValue = INT_MIN;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (!st.empty() || cur) {
        if (cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            if (cur->value <= preValue) {
                return false;
            }
            preValue = cur->value;
            cur = cur->right;
        }
    }
    
}

TreeNode* preNode = nullptr;
bool isSerchTreeRecur(TreeNode* root) {
    if (root == nullptr) return true;
    bool left = isSerchTreeRecur(root->left);
    if (!left) return false;
    if (preNode) {
        if (root->value <= preNode->value) {
            return false;
        }
    }
    preNode = root;
    return isSerchTreeRecur(root->right);
    
}

struct SerchTreeInfo
{
    bool valid;
    int min;
    int max;
    bool isSearchTree;
    SerchTreeInfo(bool v, int min, int max, bool b) : valid(v), min(min), max(max), isSearchTree(b) {}
};
bool isSerchTreeRecur1(TreeNode* root) {
    
}

SerchTreeInfo processSearchTree(TreeNode* node) {
    if (node == nullptr) {
        return {false, 0, 0, false};
    }

    SerchTreeInfo leftData = processSearchTree(node->left);
    SerchTreeInfo rightData = processSearchTree(node->right);
    int minValue = node->value;
    int maxValue = node->value;
    if (leftData.valid) {
        minValue = min(minValue, leftData.min);
        maxValue = max(maxValue, leftData.max);
    }
    if (rightData.valid) {
        minValue = min(minValue, rightData.min);
        maxValue = max(maxValue, rightData.max);
    }
    bool isBST = true;
    if (leftData.valid && (!leftData.isSearchTree || leftData.max >= node->value)) {
        isBST = false;
    }
    if (rightData.valid && (!rightData.isSearchTree || node->value >= rightData.min)) {
        isBST = false;
    }
    return {true, minValue, maxValue, isBST};
    
    
}


// 完全二叉树
bool isCompeletTree(TreeNode* root) {
    //1 任一个节点有右无左 不是二叉树
    //2 若一个节点左右不全 后面节点必须全为页节点
    if (root == nullptr) {
        return false;
    }
    queue<TreeNode*> q;
    q.push(root);
    // 是否遇到左右节点不全的节点
    bool leaf = false;
    TreeNode* cur = nullptr;
    TreeNode* l = nullptr;
    TreeNode* r = nullptr;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        l = cur->left;
        r = cur->right;
        if (!l && r) { // 左无右有
            return false;
        }
        if (leaf && (l != nullptr || r != nullptr)) {
            return false;
        }
        if (l != nullptr) q.push(l);
        if (r != nullptr) q.push(r);
        if (l == nullptr || r == nullptr) { // 左右不全
            leaf = true;
        }

    }
    return true;
}

// 一颗数是否为满二叉树
bool isAllTree(TreeNode* root) {

}



struct Info {
    bool isBalanced;
    int height;
    Info(bool b, int h) : isBalanced(b), height(h) {}
};
// 一颗树是否是平衡二叉树 
Info processBalanceTree(TreeNode* node);
bool isBalanceTree(TreeNode* root) {
    Info data = processBalanceTree(root);
    return data.isBalanced; 

}
Info processBalanceTree(TreeNode* node) {
    if (node == nullptr) {
        return Info(true, 0);
    }

    Info leftData = processBalanceTree(node->left);
    Info rightData = processBalanceTree(node->right);

    int height = max(leftData.height, rightData.height) + 1;
    bool res = leftData.isBalanced && rightData.isBalanced && fabs(leftData.height - rightData.height) < 2;
    return Info(res, height);

    /**
     * @brief 二叉树递归套路
     * 1、向左树要信息
     * 2、向右树要信息
     * 3、取信息的全集
     */
}