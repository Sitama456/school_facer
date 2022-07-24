/**
 * @file 剑指 Offer II 036. 后缀表达式.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 根据 逆波兰表示法，求该后缀表达式的计算结果。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

 

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/8Zf90G
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        int size = tokens.size();
        stack<int> st;
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < size; ++i) {
            if (isOptStr(tokens[i])) {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                if (tokens[i] == "+") {
                    st.push(num1 + num2);
                } else if (tokens[i] == "-") {
                    st.push(num2 - num1);
                } else if (tokens[i] == "*") {
                    st.push(num1 * num2);
                } else {
                    st.push(num2 / num1);
                }
            } else {
                st.push(stringToInt(tokens[i]));
            }

        }
        return st.top();
    }

    int stringToInt(string& s) {
        bool neg = false;
        int res = 0;
        for (char c : s) {
            if (c == '-') {
                neg = true;
                continue;
            }
            res = res * 10 + c - '0';
        }
        return neg ? -res : res;
    }

    bool isOptStr(string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
};