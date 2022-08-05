/**
 * @file HJ40 统计字符.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。

数据范围：输入的字符串长度满足 1 \le n \le 1000 \1≤n≤1000 

输入描述：
输入一行字符串，可以有空格

输出描述：
统计其中英文字符，空格字符，数字字符，其他字符的个数
 */

#include <iostream>
#include <string.h>
#include <string>
using namespace std;
   
bool isEnglishChar(char c);
bool isSpaceChar(char c);
bool isNumChar(char c);
int main(){
    string inputStr;
    getline(cin, inputStr);
    int englishChar = 0;
    int spaceChar = 0;
    int numChar = 0;
    int otherChar = 0;
    for (char c : inputStr) {
        if (isEnglishChar(c)) englishChar++;
        else if (isSpaceChar(c)) spaceChar++;
        else if (isNumChar(c)) numChar++;
        else otherChar++;
    }
    cout << englishChar << endl;
    cout << spaceChar << endl;
    cout << numChar << endl;
    cout << otherChar << endl;
}

bool isEnglishChar(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

bool isSpaceChar(char c) {
    return c == ' ';
}

bool isNumChar(char c) {
    return c >= '0' && c <= '9';
}

