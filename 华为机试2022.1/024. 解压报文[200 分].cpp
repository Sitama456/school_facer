/**
 * @file 024. 解压报文[200 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125155463
 * 
 */

#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

void pushStr(stack<char>& st, string str) {
    for (char c : str) {
        st.push(c);
    }
}


string decode(string& srcStr) {
    if (srcStr.empty()) return {};
    stack<char> st;
    string tmp;
    for (char c : srcStr) {
        if (c == ']') {
            tmp.clear();
            // 弹出到左括号
            while (!st.empty() && st.top() != '[') {
                tmp.push_back(st.top());
                st.pop();
            }
            reverse(tmp.begin(), tmp.end());
            // 弹出左括号
            st.pop();
            string numStr;
            // 弹出数字
            while (!st.empty() && isdigit(st.top())) {
                numStr.push_back(st.top());
                st.pop();
            }
            reverse(numStr.begin(), numStr.end());
            int num = atoi(numStr.c_str());
            while (num--) {
                pushStr(st, tmp);
            }

        } else {
            st.push(c);
        }
    }
    string res;
    res.resize(st.size());
    int i = st.size() - 1;
    while (!st.empty()) {
        res[i--] = st.top();
        st.pop();
    }
    return res;
}

int main() {
    string inputStr;
    while (1) {
        cin >> inputStr;
        cout << decode(inputStr) << endl;
    }
    return 0;
}