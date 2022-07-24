/**
 * @file 剑指 Offer II 023. 两个链表的第一个重合节点.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定两个单链表的头节点 headA 和 headB ，请找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 * 
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
        if (!headA || !headB) return NULL;
        ListNode* curA = headA;
        ListNode* curB = headB;
        int offset = 0;
        while (curA->next) {
            offset++;
            curA = curA->next;
        }
        while (curB->next) {
            offset--;
            curB = curB->next;
        }
        if (curA != curB) return NULL;
        // 长 短的指针
        ListNode* longer = offset > 0 ? headA : headB;
        ListNode* shorter = offset > 0 ? headB : headA;
        offset = offset > 0 ? offset : -offset;
        // 长的先走offset步
        while (offset--) {
            longer = longer->next;
        }

        while (longer != shorter) {
            longer = longer->next;
            shorter = shorter->next;
        }
        return longer;

    }
};