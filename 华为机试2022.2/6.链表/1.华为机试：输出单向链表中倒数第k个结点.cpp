/**
 * @file 1.华为机试：输出单向链表中倒数第k个结点.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 输出单向链表中倒数第k个结点
题目描述
输入一个单向链表，输出该链表中倒数第k个结点，链表的倒数第1个结点为链表的尾指针。
链表结点定义如下：

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};
1
2
3
4
5
正常返回倒数第k个结点指针，异常返回空指针.

要求：
(1)正序构建链表;
(2)构建后要忘记链表长度。

输入描述：
输入说明
1 输入链表结点个数
2 输入链表的值
3 输入k的值

输出描述：
输出一个整数

示例1
输入：

8
1 2 3 4 5 6 7 8
4

输出：

5
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124430837
 */

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value = 0;
    Node* next = NULL;
    Node() {}
    Node(int value) : value(value), next(NULL) { }
};

int getReverseKNode(Node* head, int k) {
    Node* cur = head;
    Node* tmp = cur;

    while (k > 0 && tmp != NULL) {
        tmp = tmp->next;
        k--;
    }
    if (k > 0) return -1;
    while (tmp != NULL) {
        cur = cur->next;
        tmp = tmp->next;
    }
    return cur->value;
}

int main(int argc, char* argv[]) {
    int n;
    int k;
    while (1) {
        cin >> n;
        vector<Node> nodes(n);
        cin >> nodes[0].value;
        for (int i = 1; i < n; ++i) {
            cin >> nodes[i].value;
            nodes[i - 1].next = &nodes[i];
        }
        cin >> k;
        cout << getReverseKNode(&nodes[0], k) << endl;
    }
    return 0;
}