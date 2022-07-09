/**
 * @file 35.复杂链表的复制.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

#define NULL 0
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* cur = head;
        Node* next = NULL;
        // 先直接在老节点后面串新的节点
        while (cur) {
            next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }

        // 修改新节点上的Random指针
        cur = head;
        while (cur) {
            next = cur->next;
            next->random = cur->random ? cur->random->next : NULL;
            cur = next->next;
        }
        cur = head;
        Node* newHead = head->next;
        Node* newCur = newHead;
        // 解耦链表
        while (cur) {
            cur->next = cur->next->next;
            newCur->next = newCur->next ? newCur->next->next : NULL;
            cur = cur->next;
            newCur = newCur->next;
        }
        return newHead;

    }
};