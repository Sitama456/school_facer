/**
 * @file 剑指 Offer II 038. 每日温度.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 请根据每日 气温 列表 temperatures ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/iIQa4I
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.empty()) return {};
        int size = temperatures.size();
        // 单调栈
        vector<int> res(size);
        stack<int> st;
        for (int i = 0; i < size; ++i) {
            int num = temperatures[i];
            while (!st.empty() && temperatures[st.top()] < num) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }
        return res;
    }
};