/**
 * @file HJ31 单词倒排.cpp
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
对字符串中的所有单词进行倒排。

说明：

1、构成单词的字符只有26个大写或小写英文字母；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；

数据范围：字符串长度满足 1 \le n \le 10000 \1≤n≤10000 
输入描述：
输入一行，表示用来倒排的句子

输出描述：
输出句子的倒排结果
 */

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

void reverse(string& str);
int main(){
    string inputStr;
    getline(cin, inputStr);
    reverse(inputStr);
    
}

bool isEnglishChar(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

void reverse(string& str) {
    if (str.empty()) return;
    int len = str.size();
    int i = len - 1;
    // 跳过结尾的非字母字符
    while (i >= 0 && !isEnglishChar(str[i])) {
        i--;
    }
    int j = i;
    while (i >= 0 && j >= 0) {
        // 跳过字母字符
        while (i >= 0 && isEnglishChar(str[i])) {
            i--;
        }
        // 此时 i 来到了非单词的字符
        cout << str.substr(i + 1, j - i);
        cout << ' ';
        // 跳过非字母字符
        while (i >= 0 && !isEnglishChar(str[i])) {
            i--;
        }
        j = i;
    }
    
}