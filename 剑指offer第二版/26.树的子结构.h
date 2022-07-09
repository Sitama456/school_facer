/**
 * @file 26.树的子结构.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

    B是A的子结构， 即 A中有出现和B相同的结构和节点值。
 * 
 */

#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    // 这个递归是为了找到B的根节点在A中的哪个位置
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) {
            return false;
        }
        // 找到了B根节点的位置
        if (A->val == B->val) {
            if (recur(A, B)) {
                return true;
            }
        }
        // 没找到 则A动B不动
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    /**
      * 判断node2是否是node1的一部分
      */
    bool recur(TreeNode* node1, TreeNode* node2) {
        if (node2 == NULL) {
            return true;
        }
        if (node1 == NULL) {
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }
        return recur(node1->left, node2->left) && recur(node1->right, node2->right);
    }
};