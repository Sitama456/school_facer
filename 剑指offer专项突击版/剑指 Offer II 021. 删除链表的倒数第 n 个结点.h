/**
 * @file 剑指 Offer II 021. 删除链表的倒数第 n 个结点.h
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
 * 给定一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fastNode = dummy;
        ListNode* slowNode = dummy;
        // 快指针先走 n 步
        int offset = n ;
        while (offset--) {
            fastNode = fastNode->next;
        }
        while (fastNode->next) {
            fastNode = fastNode->next;
            slowNode = slowNode->next;
        }
        ListNode* tmp = slowNode->next;
        slowNode->next = slowNode->next->next;
        delete tmp;
        return dummy->next;
    }
};