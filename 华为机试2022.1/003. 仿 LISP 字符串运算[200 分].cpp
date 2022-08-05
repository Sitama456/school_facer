/**
 * @file 003. 仿 LISP 字符串运算[200 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125112568
 * 
 */
#include <string>
#include <string.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

string itoa(int num) {
    if (num == 0) return "0";
    string tmp;
    bool neg = false;
    if (num < 0) {
        neg = true;
        num = -num;
    }
    while (num) {
        tmp.push_back((num % 10) - '0');
        num /= 10;
    }
    if (neg) {
        tmp.push_back('-');
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

string LISP_OP(string str) {
    // 分割字符串
    vector<string> ops;
    char* tmp = strtok((char*)str.data(), " ");
    while (tmp != NULL) {
        ops.push_back(tmp);
        tmp = strtok(NULL, " ");
    }
    string res;
    // op num1 num2
    int num1 = atoi(ops[1].c_str());
    int num2 = atoi(ops[2].c_str());
    string& op = ops[0];
    if (op == "add") {
        return itoa(num1 + num2);
    } else if (op == "sub") {
        return itoa(num1 - num2);
    } else if (op == "div") {
        if (num2 == 0) return "error";
        return itoa(num1 / num2);
    } else if (op == "mul") {
        return itoa(num1 * num2);
    }
    return "error";
}

string LISP_result(string& lispStr) {
    stack<char> st;
    for (char c : lispStr) {
        if (c == ')') {
            // 弹出相应的字符
            string tmp;
            while (!st.empty()) {
                char t = st.top();
                st.pop();
                tmp.push_back(t);
                if (t == '(') break;   
            }
            reverse(tmp.begin(), tmp.end());
            string op_res = LISP_OP(tmp);
            if (op_res == "error") return op_res;
            for (char t : op_res) {
                st.push(t);
            } 
        }
    }
    string res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}