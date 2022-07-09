/**
 * @file 30.包含min函数的栈.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
 * 
 */
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        in.push(x);
        if (out.empty()) {
            return out.push(x);
        }
        out.push(x < out.top() ? x : out.top());
    }
    
    void pop() {
        in.pop();
        out.pop();
    }
    
    int top() {
        return in.top();
    }
    
    int min() {
        return out.top();
    }
private:
    stack<int> in, out;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */