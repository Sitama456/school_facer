/**
 * @file 18.删除链表的节点.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。
 * 
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
                break;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};