/**
 * @file 31.栈的压入弹出序列.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int size = pushed.size();
        if (pushed.size() != popped.size()) {
            return false;
        }
        if (pushed.empty()) {
            return true;
        }
        int i = 0; // poped的指针
        stack<int> pushStack;
        for (auto num : pushed) {
            pushStack.push(num);
            // 如果栈顶元素与弹出序列相等 则一直弹出
            while (!pushStack.empty() && pushStack.top() == popped[i]) {
                pushStack.pop();
                i++;
            }
        }
        return pushStack.empty();
    }
};