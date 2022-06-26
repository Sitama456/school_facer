/**
 * @file 06.从尾到头打印链表.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 */

#include <vector>
#include <stack>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 


class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if (head == NULL) {
            return res;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        stack<ListNode*> st;
        ListNode* cur = dummy->next;
        while (cur != NULL) {
            st.push(cur);
            cur = cur->next;
        }
        while (!st.empty()) {
            ListNode* node = st.top();
            st.pop();
            res.push_back(node->val);
        }
        return res;
    }
};