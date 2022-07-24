/**
 * @file 剑指 Offer II 027. 回文链表.h
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
 * 给定一个链表的 头节点 head ，请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。
 * 
 */


#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode* cur = head;
        while (cur) {
            st.push(cur);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            if (cur->val != st.top()->val) {
                return false;
            }
            cur = cur->next;
            st.pop();
        }
        return true;
    }
};