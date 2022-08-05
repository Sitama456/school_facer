/**
 * @file 9.华为机试：报文解压缩.cpp
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
 * 【编程题目 | 200分】报文解压缩 [ 200 / 中等 ]

题目描述
为了提升数据传输的效率，会对传输的报文进行压缩处理。
输入一个压缩后的报文，请返回它解压后的原始报文。
压缩规则：n[str]，表示方括号内部的 str 正好重复 n 次。
注意 n 为正整数（0 < n <= 100），str只包含小写英文字母，不考虑异常情况。
输入描述
输入压缩后的报文：

1）不考虑无效的输入，报文没有额外的空格，方括号总是符合格式要求的；
2）原始报文不包含数字，所有的数字只表示重复的次数 n ，例如不会出现像 5b 或 3[8] 的输入；

输出描述
解压后的原始报文

注：
1）原始报文长度不会超过1000，不考虑异常的情况

示例
输入
3[m2[c]]
1
输出
mccmccmcc
1
说明

m2[c] 解压缩后为 mcc，重复三次为 mccmccmcc

输入
10[k]2[mn3[j2[op]]]
1
输出
kkkkkkkkkkmnjopopjopopjopopmnjopopjopopjopop
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/125821075
 */

#include <string>
#include <string.h>
#include <stack>
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;

string decode(string str) {
    stack<char> st;
  
    for (char c : str) {
        if (c == ']') {
            // 弹出到'['
            string tmps;
            while (!st.empty() && st.top() != '[') {
                tmps.push_back(st.top()),
                st.pop();
            }
            // 弹出'['
            st.pop();
            reverse(tmps.begin(), tmps.end());
            // 弹出个数
            string countStr;
            while (!st.empty() && isdigit(st.top())) {
                countStr.push_back(st.top());
                st.pop();
            } 
            reverse(countStr.begin(), countStr.end());
            int count = atoi(countStr.c_str());
            for (int i = 0; i < count; ++i) {
                for (char t : tmps) {
                    st.push(t);
                }
            }
        } else {
            st.push(c);
        }
    }
    int len = st.size();
    string res(len, 0);
    for (int i = len - 1; i >= 0; --i) {
        res[i] = st.top();
        st.pop();
    }
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        cout << decode(inputStr) << endl;
    }
    return 0;
}