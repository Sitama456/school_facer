/**
 * @file 22.链表中倒数第k个节点.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* tmp = cur;
        while (k && tmp) {
            tmp = tmp->next;
            k--;
        }
       
        while (tmp && tmp->next) {
            cur = cur->next;
            tmp = tmp->next;
        }
        return cur->next;
    }
};