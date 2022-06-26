/**
 * @file 07.重建二叉树.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

    假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 */

#include <vector>
#include <map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        return process(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inorderIndex);
    }

    // 前序: 中 左 右
    // 中序: 左 中 右
    TreeNode* process(vector<int>& preorder, vector<int>& inorder, int preLeft, 
                        int preRight, int inLeft, int inRight, map<int, int>& inorderIndex) {
        // 左闭右闭区间
        if (preLeft > preRight) {
            return NULL;
        }
        //1、找到分割点 即当前树的根节点
        int rootNum = preorder[preLeft];
        int rootInorderIndex = inorderIndex[rootNum];
        //2、创建根节点
        TreeNode* rootNode = new TreeNode(rootNum);
        //3. 建立右树
        int rightTreeInLeft = rootInorderIndex + 1;
        int rightTreeInRight = inRight;
        int rightTreePreRight = preRight;
        // 长度相等
        int rightTreePreLeft = rightTreePreRight - (rightTreeInRight - rightTreeInLeft);

        rootNode->right = process(preorder, inorder, rightTreePreLeft, rightTreePreRight,
                        rightTreeInLeft, rightTreeInRight, inorderIndex);

        //4、建立左树
        int leftTreePreLeft = preLeft + 1;
        int leftTreePreRight = rightTreePreLeft - 1;
        int leftTreeInLeft = inLeft;
        int leftTreeInRight = rootInorderIndex - 1;
        rootNode->left = process(preorder, inorder, leftTreePreLeft, leftTreePreRight, leftTreeInLeft, leftTreeInRight, inorderIndex);
        return rootNode;
    }
};