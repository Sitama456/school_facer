/**
 * @file 2.华为机试：最大嵌套括号深度.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 编程题目 | 100分】最大嵌套括号深度 [ 100 / 中等 ]

最大嵌套括号深度
题目描述：
现有一字符串仅由 ‘(’， ‘)’， ‘{’， ‘}’， ‘[’， ']'六种括号组成。 若字符串满足以下条件之一，则为无效字符串：

①任一类型的左右括号数量不相等；
②存在未按正确顺序（先左后右）闭合的括号。
输出括号的最大嵌套深度，若字符串无效则输出 0。 0≤字符串长度≤100000

输入描述:
一个只包括 ‘(’， ‘)’， ‘{’， ‘}’， ‘[’， ']'的字符串

输出描述：
一个整数，最大的括号深度

示例 1：

输入
[]
1
输出
1
1
说明
有效字符串，最大嵌套深度为1

示例 2：

输入
([]{()})
1
输出
3
1
说明
有效字符串，最大嵌套深度为3

示例 3：

输入
(]
1
输出
0
1
说明
无效字符串，有两种类型的左右括号数量不相等

示例 4：

输入
([)]
1
输出
0
1
说明
无效字符串，存在未按正确顺序闭合的括号
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123946643
 */

#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

bool pop(stack<char>& st, char c) {
    while (!st.empty()) {
        char t = st.top();
        st.pop();
        if (t == c) return true;
    }
    return false;
}

bool isLeftPart(char c) {
    return c == '(' || c == '[' || c == '{';
}

int maxDepth(string& str) {
    int res = 0;
    int count = 0;
    stack<char> st;
    for (char c : str) {
        if (c == ')') {
            count--;
            if (!pop(st, '(')) {
                return 0;
            }
        } else if (c == '}') {
            count--;
            if (!pop(st, '{')) {
                return 0;
            }
        } else if (c == ']') {
            count--;
            if (!pop(st, '[')) {
                return 0;
            }
        } else {
            if (isLeftPart(c)) {
                count++;
                res = max(res, count);
            }
            st.push(c);
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while(1) {
        cin >> inputStr;
        cout << maxDepth(inputStr) << endl;
    }
    return 0;
}