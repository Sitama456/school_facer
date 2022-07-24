/**
 * @file HJ10 字符个数统计.cpp
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
编写一个函数，计算字符串中含有的不同字符的个数。字符在 ASCII 码范围内( 0~127 ，包括 0 和 127 )，换行表示结束符，不算在字符里。不在范围内的不作统计。多个相同的字符只计算一次
例如，对于字符串 abaca 而言，有 a、b、c 三种不同的字符，因此输出 3 。

数据范围： 1 \le n \le 500 \1≤n≤500 
输入描述：
输入一行没有空格的字符串。

输出描述：
输出 输入字符串 中范围在(0~127，包括0和127)字符的种数。
 */

#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(){
    char c = 0;
    int i = 0;
    int cnt = 0;
    set<char> s;
    while (cin >> c) {
        if (c >= 0 && c <= 127) {
            s.insert(c);
        }
    }
    cout << s.size();
    return 0;
}