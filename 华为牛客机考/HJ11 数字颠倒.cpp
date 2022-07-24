/**
 * @file HJ11 数字颠倒.cpp
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
输入一个整数，将这个整数以字符串的形式逆序输出
程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001


数据范围： 0 \le n \le 2^{30}-1 \0≤n≤2 
30
 −1 
输入描述：
输入一个int整数

输出描述：
将这个整数以字符串的形式逆序输出
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int num = 0;
    cin >> num;
    string s;
    while (num) {
        int re = num % 10;
        s.push_back(re - 0 + '0');
        num /= 10;
    }
    cout << atoi(s.c_str());
    return 0;
}