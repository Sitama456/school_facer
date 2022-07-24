/**
 * @file HJ9 提取不重复的整数.cpp
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
输入一个 int 型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
保证输入的整数最后一位不是 0 。

数据范围： 1 \le n \le 10^{8} \1≤n≤10 
8
  
输入描述：
输入一个int型整数

输出描述：
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
 */

#include <iostream>
#include <string>
#include <set>
using namespace std;
 
int main(){
    int num = 0;
    cin >> num;
    set<int> s;
    string res;
    while (num) {
        int num1 = num % 10;
        if (s.find(num1) == s.end()) {
            res.push_back(num1 - 0 +'0');
            s.insert(num1);
        }
        num /= 10;
    }
    cout << atoi(res.c_str());
    return 0;
}