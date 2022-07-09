/**
 * @file 36.二叉搜索树与双向链表.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

 

为了让您更好地理解问题，以下面的二叉搜索树为例：

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * 
 */

// Definition for a Node.
#define NULL 0
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    // 中序遍历 左 中 右
    Node* treeToDoublyList(Node* root) {
       if (root == NULL) {
           return NULL;
        }
        process(root);
        // head 为头指针 pre为尾指针 需要连起来
        head->left = pre;
        pre->right = head;
        return head;
    }

    void process(Node* node) {
        if (node == NULL) {
            return;
        }
        // 左
        process(node->left);
        // 中
        if (pre == NULL) { // 表示正在访问的是链表的节点
            head = node;
        } else {
            pre->right = node;
        }
        node->left = pre;
        pre = node;
        // 右
        process(node->right);
    }

private:
    Node *head = NULL, *pre = NULL;
};
