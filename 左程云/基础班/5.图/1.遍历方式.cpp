/**
 * @file 1.遍历方式.cpp 宽度优先遍历 广度优先遍历
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "grath.h"
#include <queue>
#include <stack>
#include <set>
#include <iostream>
using namespace std;


/**
 * @brief 宽带优先遍历
 * 1. 利用队列实现
 * 2. 从源节点开始一次按照宽度进队列，然后弹出
 * 3. 每弹出一个点，把该点所有没有进过队列的邻接点放入队列
 * 4. 直到队列变空
 * 
 * @param node 
 */
void bfs(Node* node) {
    if (node == nullptr) {
        return;
    }
    queue<Node*> q;
    set<Node*> s;
    q.push(node);
    s.insert(node); // 防止重复
    cout << node->value << endl;
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        cout << cur->value << endl;
        for (Node* next : cur->nexts) {
            if (s.find(next) == s.end()) {
                s.insert(next);
                q.push(cur);
            }
        }
        

    }


}

/**
 * @brief 深度优先遍历 ： 如果一条路没有走过 先走到黑
 * 1. 利用栈实现
 * 2. 从源节点开始把节点按照深度放入栈，然后弹出
 * 3. 每弹出一个点，把该点的下一个没有进过栈的邻接点放入栈
 * 4. 直到栈变空
 * 
 */

void dfs(Node* node) {
    if (node == nullptr) {
        return;
    }
    stack<Node*> st;
    set<Node*> s;
    st.push(node);
    s.insert(node);
    cout << node->value << endl;
    while (!st.empty()) {
        Node* cur = st.top();
        st.pop();
        for (Node* next : cur->nexts) {
            if (s.find(next) == s.end()) {
                st.push(cur);
                st.push(next);
                s.insert(next);
                cout << next->value << endl;
                // 注意这里就先不看其他邻接点了 直接break
                break;
            }

        }
    }
}