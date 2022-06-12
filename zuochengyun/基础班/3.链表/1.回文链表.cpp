/*
 * @Description: 
 * @Author: mzm
 * @Date: 2022-05-29 19:26:11
 * @LastEditTime: 2022-05-29 20:00:21
 * @LastEditors: mzm
 */
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
    int value = 0;
    ListNode* next = nullptr;
};

bool isPalindrome(ListNode* head) {
    if (head == nullptr) {
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    stack<int> st;
    while (slow->next) {
        slow = slow->next;
        st.push(slow->value);
    }
    ListNode* help = head;
    while (st.empty()) {
        if (help->value != st.top()) {
            return false;
        }
        st.pop();
    }
    return true;
    
}


bool isPalindrome1(ListNode* head) {
    if (head == nullptr) {
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    // slow到达中间结点
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    fast = slow->next;
    slow->next = nullptr;
    ListNode* help = nullptr;
    // slow 到达尾结点
    while (fast != nullptr) {
        help = fast->next;
        fast->next = slow;
        slow = fast;
        fast = help;
    }
    fast = slow; // 尾结点
    help = head; // 头结点
    bool res = true;
    while (help && fast) {
        if (help->value != fast->value) {
            res = false;
            break;
        }
        help = help->next;
        fast = fast->next;
    }
    // 逆序回来
    fast = slow->next;
    slow->next = nullptr;
    while (fast) {
        help = fast->next;
        fast->next = slow;
        slow = fast;
        fast = help;
    }
    return res;
    
}