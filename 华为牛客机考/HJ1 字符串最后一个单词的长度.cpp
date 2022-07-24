/**
 * @file HJ1 字符串最后一个单词的长度.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）
输入描述：
输入一行，代表要计算的字符串，非空，长度小于5000。

输出描述：
输出一个整数，表示输入字符串最后一个单词的长度。
 */

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;


int main(){
    vector<string> str;
    string s;
    while (cin >> s) {
        str.push_back(s);
    }
    cout << str[str.size() - 1].size();
    return 0;
    
}
