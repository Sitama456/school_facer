/**
 * @file 4.后继节点.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr), parent(nullptr) {}
};


/**
 * @brief 后继节点
 *  上述结构比普通二叉树节点多了一个指向父节点的parent指针。树中每个节点的parent指针
 * 都正确指向自己的父节点，头节点的parent指向nullptr。
 * 只给一个在二叉树中的某个节点node，请实现返回node的后继节点的函数.
 * 后继节点: 中序遍历中，node的下一个节点叫做后继节点 
 * 假设该节点到其后继节点的距离为k, 复杂度能否做到O(k)
 */
// 中序遍历: 左 中 右
// 1) x 有右树:右树的最左节点是其后继
// 2) x 无有树: 往上走，看自己是不是父亲的左孩子，不是继续往上走，是的话说明
//    该节点是其左树中最右的孩子
// 3) 二叉树中最右孩子没有后继节点

TreeNode* findNextNode(TreeNode* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right) {
        // 第一种情况 有右孩子
        while (node->left) {
            node = node->left;
        }
        return node;
    } else {
        // 第二种情况 无右孩子 
        TreeNode* parent = node->parent;
        while (parent && parent->left != node) { // 我是不是父亲的左孩子
            node = parent;
            parent = node->parent;
        }
        return parent;
    }
}