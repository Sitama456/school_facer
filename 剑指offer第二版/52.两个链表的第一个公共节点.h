/**
 * @file 52.两个链表的第一个公共节点.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 输入两个链表，找出它们的第一个公共节点。

如下面的两个链表：
在节点 c1 开始相交。
 */

#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *NodeA = headA;
        ListNode *NodeB = headB;
        int size = 0;
        while (NodeA && NodeA->next) {
            size++;
            NodeA = NodeA->next;
        }
        while (NodeB && NodeB->next) {
            size--;
            NodeB = NodeB->next;
        }
        if (NodeA != NodeB) return NULL;
        ListNode* longNode = size > 0 ? headA : headB;
        ListNode* shortNode = longNode == headA ? headB : headA;
        size = size > 0 ? size : -size;
        while (size--) {
            longNode = longNode->next;
        }
        while (1) {
            if (longNode == shortNode) {
                return longNode;
            }
            longNode = longNode->next;
            shortNode = shortNode->next;
        }
        return NULL;
    }
};