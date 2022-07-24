/**
 * @file HJ26 字符串排序.cpp
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
编写一个程序，将输入字符串中的字符按如下规则排序。

规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。

如，输入： Type 输出： epTy

规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。

如，输入： BabA 输出： aABb

规则 3 ：非英文字母的其它字符保持原来的位置。


如，输入： By?e 输出： Be?y

数据范围：输入的字符串长度满足 1 \le n \le 1000 \1≤n≤1000 

输入描述：
输入字符串
输出描述：
输出字符串
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string sortStr(string& str);
int main(){
    string inputStr;
    getline(cin, inputStr);
    cout << sortStr(inputStr);
    return 0;
}


string sortStr(string& str) {
    // 桶排序
    int len = str.size();
    vector<char> vec;
    // 英文字母从A到Z排列 不区分大小写
    // 同一英文字母按输入顺序排列
    for (int j = 0; j < 26; ++j) {
        for (int i = 0; i < len; ++i) {
            if (str[i] - 'a' == j || str[i] - 'A' == j) {
                vec.push_back(str[i]);
            }
        }
    }
    // 非英文字母位置不变
    int k = 0;
    for (int i = 0; i < len; ++i) {
        char c = str[i];
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            str[i] = vec[k++];
        }
    }
    return str;
}