/**
 * @file 4. 链表相交问题.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <math.h>
struct Node
{
    int value;
    Node* next;
    Node(int value = 0) : value(value), next(nullptr) {

    }
};


/**
 * @brief 两个单链表相交问题
 * 给定两个可能有环也可能无环的单链表，头节点为head1和head2。请实现一个函数，如果两个
 * 链表相交，请返回相交的第一个节点。如果不相交，返回null
 * 要求：如果两个链表长度之和为N，时间复杂度请达到O(N), 空间复杂度O(1)
 * 
 */

/**
 * @brief 判断链表是否有环 
 * 
 * @param head 
 * @return Node* 
 */
Node* circleEntry(Node* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return nullptr;
    }
    Node* slow = head->next;
    Node* fast = head->next->next;
    while (slow != fast) {
        if (fast == nullptr||fast->next == nullptr)
            return nullptr;
        slow = slow->next;
        fast = fast->next->next;
       
    }
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;

}

Node* noLoop(Node* head1, Node* head2);
Node* crossNode(Node* head1, Node* head2) {
    Node* loopEntry1 = circleEntry(head1);
    Node* loopEntry2 = circleEntry(head2);
    
    Node* res;
    // 两个链表都无环
    if (loopEntry1 == nullptr && loopEntry2 == nullptr) {
        return noLoop(head1, head2);
    } else if (loopEntry1 && loopEntry2) { // 两个都有环 
        if (loopEntry1 == loopEntry2) {
            Node* tmp = loopEntry1->next;
            loopEntry1->next = nullptr;
            res = noLoop(head1, head2);
            loopEntry1->next = tmp;
            return res;
        } else {
            Node* tmp = loopEntry1->next;
            while (tmp != loopEntry1) {
                if (tmp == loopEntry2) {
                    return loopEntry1;
                }
                tmp = tmp->next;
            }
            return nullptr;
        }
    } else { // 一个有环 一个无环 不可能相交
        return nullptr;
    }
}
/**
 * @brief 两个链表都无环
 * 
 * @param head1 
 * @param head2 
 * @return Node* 
 */
Node* noLoop(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return;
    }
    Node* cur1 = head1;
    Node* cur2 = head2;
    int n = 0;
    while (cur1->next) {
        n++;
        cur1 = cur1->next;
    }
    while (cur2->next) {
        n--; 
        cur2 = cur2->next;
    }
    if (cur1 != cur2) return nullptr;
    cur1 = n > 0 ? head1 : head2;
    cur2 = cur1 == head1 ? head2 : head1;
    while (fabs(n) != 0) {
        cur1 = cur1->next;
    }
    while (cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}