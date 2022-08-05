/**
 * @file 3.华为机试：字符串消除.cpp
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
 * 【编程题目 | 100分】字符串消除 [ 100 / 简单 ]

字符串消除
题目描述：
游戏规则： 输入一个只包含英文字母的字符串, 字符串中的两个字母如果相邻且相同,就可以消除。 在字符串上反复执行消除的动作, 直到无法继续消除为止,此时游戏结束。 输出最终得到的字符串长度.

输入描述:
输入原始字符串str 只能包含大小写英文字母,字母的大小写敏感, str长度不超过100

输出描述：
输出游戏结束后,最终得到的字符串长度

示例 1：

输入
gg
1
输出
0

说明
gg可以直接消除 得到空串 长度为0

示例 2：

输入
mMbccbc
1
输出
3

说明
mMbccbc中 可以先消除cc 此时变为mMbbc 再消除 bb 此时变成mMc 此时没有相同且相邻的字符 无法继续消除 最终得到字符串mMc 长度为3

备注：
输入中包含非大小写英文字母时 均为异常输入 直接返回0
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123947034
 */

#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool isEnglishChar(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int strRemove(string& str) {
    stack<char> st;
    for (char c : str) {
        if (!isEnglishChar(c)) {
            return 0;
        }
        if (!st.empty() && st.top() == c) {
            while (!st.empty() && st.top() == c) {
                st.pop();
            }
        } else {
            st.push(c);
        }     
    }
    return st.size();
}

int main(int argc, char* argv[]) {
    string inputStr;
    while(1) {
        cin >> inputStr;
        cout << strRemove(inputStr) << endl;
    }
    return 0;
}