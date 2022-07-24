/**
 * @file 1.非递归遍历.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stack>
using namespace std;
struct TreeNode
{
    int value = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value = 0) : value(value), left(nullptr), right(nullptr) { }
};

/**
 * @brief 先序遍历 中 左 右 
 * 
 * @param root 
 */
void preOrderUnRecur(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* cur = st.top();
        st.pop();
        // 处理节点
        // ...
        // 处理完毕
        if (cur->right) st.push(cur->right);
        if (cur->left) st.push(cur->left);
      
    }
    
}

/**
 * @brief 中序遍历 左 中 右
 * 
 * 先压左边界，弹出即处理，再压右子树
 * @param root 
 */
void inOrderUnRecur(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> st;
    while (!st.empty() || root != nullptr) {
        if (root != nullptr) {
            st.push(root);
            root = root->left;
        } else {
            root = st.top();
            st.pop();
            // 处理节点
            // ...
            root = root->right;
        }
    }

}

/**
 * @brief 后续遍历 左右中  ->  中右左
 * 
 * @param root 
 */
void postOrderUnRecur(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);
    while (!st1.empty()) {
        TreeNode* cur = st1.top();
        st1.pop();
        st2.push(cur);
        if (cur->left) st1.push(cur->left);
        if (cur->right) st1.push(cur->right);
    }
    while (!st2.empty()) {
        TreeNode* cur = st2.top();
        st2.pop();
        // 处理节点
    }


}

#include <queue>
void layerVisit(TreeNode* head) {
    if (head == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(head);
    int n = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* cur = q.front();
            q.pop();
            // 处理节点
            //
            //
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
}