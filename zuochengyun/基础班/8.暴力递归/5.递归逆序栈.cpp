/**
 * @file 5.递归逆序栈.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给你一个栈，请你逆序这个栈，只能用递归函数
 * 
 */

#include <stack>
#include <vector>
using namespace std;

/**
 * @brief 得到并移除栈底元素
 * 
 * @param st 
 * @return int 
 */
int getAndRemoveBottom(stack<int>& st) {
    int result = st.top();
    st.pop();
    if (st.empty()) {
        return result;
    }
    int next = getAndRemoveBottom(st);
    st.push(result);
    return next;
}

void reverseStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }
    int i = getAndRemoveBottom(st);
    reverseStack(st);
    st.push(i);
}