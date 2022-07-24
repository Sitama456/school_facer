/**
 * @file 剑指 Offer II 025. 链表中的两数相加.h
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
 * 给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

可以假设除了数字 0 之外，这两个数字都不会以零开头。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/lMSNwu
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        // 进位
        int count = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* res = nullptr;
        ListNode* resHead = nullptr;
        while (cur1 || cur2) {
            int val1 = cur1 ? cur1->val : 0;
            int val2 = cur2 ? cur2->val : 0;
            int sum = val1 + val2 + count;
            if (res == nullptr) {
                res = new ListNode(sum % 10);
                resHead = res;
            } else {
                res->next = new ListNode(sum % 10);
                res = res->next;
            }  
            count = sum / 10;
            cur1 = cur1 ? cur1->next : nullptr;
            cur2 = cur2 ? cur2->next : nullptr;
        }
        if (count != 0) {
            res->next = new ListNode(count);
            res = res->next;
        }
        return reverseList(resHead);
    }

    // 反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};