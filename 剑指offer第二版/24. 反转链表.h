/**
 * @file 24. 反转链表.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 * 
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *prev = nullptr;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};