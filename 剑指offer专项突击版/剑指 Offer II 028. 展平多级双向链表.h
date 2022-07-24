/**
 * @file 剑指 Offer II 028. 展平多级双向链表.h
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
 * 多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给定位于列表第一级的头节点，请扁平化列表，即将这样的多级双向链表展平成普通的双向链表，使所有结点出现在单级双链表中。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/Qv1Da2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#define NULL 0
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;
        process(head);
        return head;

    }
    // 深度优先遍历
    // 返回子级链表的最后一个值
    Node* process(Node* head) {
        Node* cur = head;
        Node* last = NULL;
        Node* next = NULL;
        while (cur) {
            // 处理子级链表
            if (cur->child) {
                Node* child_last = process(cur->child);
                next = cur->next;
                // 将子级别结构链接到当前结构来
                cur->next = cur->child;
                cur->child->prev = cur;
                // 如果next不为空
                if (next) {
                    child_last->next = next;
                    next->prev = child_last;
                }
                cur->child = NULL;
            } else {
                last = cur;
            }
            cur = cur->next;
        }
        return last;
    }
};