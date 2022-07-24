/**
 * @file HJ2 计算某字符出现次数.cpp
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
写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）

数据范围： 1 \le n \le 1000 \1≤n≤1000 
输入描述：
第一行输入一个由字母和数字以及空格组成的字符串，第二行输入一个字符。

输出描述：
输出输入字符串中含有该字符的个数。（不区分大小写字母）
 */

#include<iostream>
#include<string>
#include <map>
using namespace std;



int getNumberOfChar(string s, char spec) {
    map<char , int> cnt;
    for (char c : s) {
        c = c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
        cnt[c]++;
    }
    spec = spec >= 'A' && spec <= 'Z' ? spec - 'A' + 'a' : spec;
    return cnt[spec];
    
}

int main(){
    char s[1001];
    char spec;
    cin.getline(s, 1001);
        cin >> spec;
        cout << getNumberOfChar(s, spec);
    

}