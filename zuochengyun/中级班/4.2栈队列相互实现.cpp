/**
 * @file 4.2栈队列相互实现.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 如何使用栈实现队列 如何使用队列使用栈
 * 
 */

#include <stack>
#include <queue>
using namespace std;

class MyQueue {
public:
    stack<int> stackPush, stackPop;



};

class MyStack {
public:
    queue<int> queueL, queueR;

};