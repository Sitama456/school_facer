/**
 * @file 59.2.队列的最大值.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <queue>
#include <deque>
using namespace std;
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (values.empty()) {
            return -1;
        }
        return maxValues.front();
    }
    
    void push_back(int value) {
        values.push(value);
        // 维护一个单调的双端队列
        while (!maxValues.empty() && maxValues.back() < value) {
            maxValues.pop_back();
        }
        maxValues.push_back(value);
    }
    
    int pop_front() {
        if (values.empty()) {
            return -1;
        }
        int v = values.front();
        if (v == maxValues.front()) {
            maxValues.pop_front();
        }
        values.pop();
        return v;
    }
private:
    queue<int> values;
    deque<int> maxValues;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */