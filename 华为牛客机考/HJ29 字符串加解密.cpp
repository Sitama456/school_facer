/**
 * @file HJ29 字符串加解密.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
对输入的字符串进行加解密，并输出。

加密方法为：

当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；

当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；

其他字符不做变化。

解密方法为加密的逆过程。
数据范围：输入的两个字符串长度满足 1 \le n \le 1000 \1≤n≤1000  ，保证输入的字符串都是只由大小写字母或者数字组成
输入描述：
第一行输入一串要加密的密码
第二行输入一串加过密的密码

输出描述：
第一行输出加密后的字符
第二行输出解密后的字符
 */

#include <string>
#include <iostream>
using namespace std;

string encode(string& str);
string decode(string& str);
int main() {
    string inputStr1;
    string inputStr2;
    cin >> inputStr1;
    cin >> inputStr2;
    cout << encode(inputStr1) << endl;
    cout << decode(inputStr2) << endl;
}

string encode(string& str) {
    string res;
    for (char c : str) {
        // 如果是大写字母
        if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + 1) % 26 + 'A';
            c = c - 'A' + 'a';
        } else if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + 1) % 26 + 'a';
            c = c - 'a' + 'A';
        } else if (c >= '0' && c <= '9') {
            c = (c - '0' + 1) % 10 + '0';
        }
        res.push_back(c);
    }
    return res;
}

string decode(string& str) {
    string res;
    for (char c : str) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
            c = c == 'a' ? 'z' : c - 1;
        } else if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
            c = c == 'A' ? 'Z' : c - 1;
        } else if (c >= '0' && c <= '9') {
            c = c == '0' ? '9' : c - 1;
        }
        res.push_back(c);
    }
    return res;
}
