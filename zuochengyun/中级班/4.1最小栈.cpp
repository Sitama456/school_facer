/**
 * @file 4.1最小栈.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返回栈中最小
 * 元素的操作。
 * 要求: 1.pop push getMin操作的时间复杂度都是O(1)
 * 2 设计的栈类型可以使用现有数据结构
 * 
 */

#include <stack>
using namespace std;
class minStack {
public:
    stack<int> data, min;
    minStack() {

    }

    void push(int num) {
        if (data.empty()) {
            data.push(num);
            min.push(num);
        } else {
            data.push(num);
            if (num < min.top()) {
                min.push(num);
            } else {
                min.push(min.top());
            }
        }
    }

    void pop() {
        if (data.empty()) {
            return;
        }
        data.pop();
        min.pop();
    }
};