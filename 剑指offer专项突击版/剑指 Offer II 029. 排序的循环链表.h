/**
 * @file 剑指 Offer II 029. 排序的循环链表.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定循环单调非递减列表中的一个点，写一个函数向这个列表中插入一个新元素 insertVal ，使这个列表仍然是循环升序的。

给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。

如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。

如果列表为空（给定的节点是 null），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/4ueAj6
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#define NULL 0
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }

        // 如果只有一个节点
        if (head->next == head) {
            Node* node = new Node(insertVal);
            head->next = node;
            node->next = head;
            return head;
        }

        // 多于一个节点
        Node* cur = head;
        Node* next = cur->next;
        // 找到合适的区间
        while (next != head) {
            // 在 cur 与 next 之间
            if (cur->val <= insertVal && next->val >= insertVal) {
                break;
            }
            // 到达原来链表的最大值与最小值之间了
            if (cur->val > next->val) {
                if (insertVal >= cur->val || insertVal <= next->val) {
                    break;
                }
            }
            cur = next;
            next = cur->next;
        }
        // 否则就是全部节点相等的情况 随便插入哪里都行

        Node* node = new Node(insertVal);
        cur->next = node;
        node->next = next;
        return head;
    }
};