/**
 * @file 剑指 Offer II 026. 重排链表.h
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
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：

 L0 → L1 → … → Ln-1 → Ln 
请将其重新排列后变为：

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/LGjMqU
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        // 快慢指针
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 从slow开始反转链表
        ListNode* pre = slow;
        ListNode* cur = slow->next;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        slow->next = nullptr;
        // 此时pre来到了右端链表的第一个
        ListNode* left = head; 
        ListNode* right = pre;
        // 分别对应偶数情况和奇数情况
        // 建议在纸上画一画
        while (left && left != right) {
            ListNode* tmp1 = left->next;
            ListNode* tmp2 = right->next;
            left->next = right;
            right->next = tmp1;
            left = right->next;
            right = tmp2;
        }
        return;
    }
 };