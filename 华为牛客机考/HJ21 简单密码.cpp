/**
 * @file HJ21 简单密码.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
现在有一种密码变换算法。
九键手机键盘上的数字与字母的对应： 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0，把密码中出现的小写字母都变成九键键盘对应的数字，如：a 变成 2，x 变成 9.
而密码中出现的大写字母则变成小写之后往后移一位，如：X ，先变成小写，再往后移一位，变成了 y ，例外：Z 往后移是 a 。
数字和其它的符号都不做变换。
数据范围： 输入的字符串长度满足 1 \le n \le 100 \1≤n≤100 
输入描述：
输入一组密码，长度不超过100个字符。

输出描述：
输出密码变换后的字符串
 */

#include<iostream>
#include<string>
#include <unordered_map>
using namespace std;

void translate(string& s, unordered_map<char, int>& mp);

int main(){
    unordered_map<char, int> mp;
    mp['a'] = 2;
    mp['b'] = 2;
    mp['c'] = 2;
    
    mp['d'] = 3;
    mp['e'] = 3;
    mp['f'] = 3;
    
    mp['g'] = 4;
    mp['h'] = 4;
    mp['i'] = 4;
    
    mp['j'] = 5;
    mp['k'] = 5;
    mp['l'] = 5;
    
    mp['m'] = 6;
    mp['n'] = 6;
    mp['o'] = 6;
    
    mp['p'] = 7;
    mp['q'] = 7;
    mp['r'] = 7;
    mp['s'] = 7;
    
    mp['t'] = 8;
    mp['u'] = 8;
    mp['v'] = 8;
    
    mp['w'] = 9;
    mp['x'] = 9;
    mp['y'] = 9;
    mp['z'] = 9;
    string inputStr;
    while (cin >> inputStr) {
        translate(inputStr, mp);
        cout << inputStr << endl;
    }
    return 0;
    
}

void translate(string& s, unordered_map<char, int>& mp) {
    for (char& c : s) {
        if (isdigit(c)) {
            continue;
        }
        if (c >= 'A' && c <= 'Z') {
            if (c == 'Z') c = 'a';
            else {
                c = c - 'A' + 'a' + 1;
            }
            
        } else {
            c = mp[c] + '0';
        }
    } 
}
