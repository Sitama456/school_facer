/**
 * @file HJ14 字符串排序.cpp
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
给定 n 个字符串，请对 n 个字符串按照字典序排列。

数据范围： 1 \le n \le 1000 \1≤n≤1000  ，字符串长度满足 1 \le len \le 100 \1≤len≤100 
输入描述：
输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
输出描述：
数据输出n行，输出结果为按照字典序排列的字符串。
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string& s1, string& s2) {
    int size1 = s1.size();
    int size2 = s2.size();
    int i1 = 0;
    int i2 = 0;
    while (i1 < size1 && i2 < size2) {
        char c1 = s1[i1++];
        char c2 = s2[i2++];
        if (c1 < c2) {
            return true;
        } else if (c1 > c2) {
            return false;
        } else {
            
        }
    }
    return i1 == size1 ? true : false;
}
int main(){
    int num = 0;
    cin >> num;
    vector<string> strs;
    string str;
    while (num--) {
        cin >> str;
        strs.push_back(str);
    }
    sort(strs.begin(), strs.end(), cmp);
    for (string& str : strs) {
        cout << str << endl;
    }
    return 0;
}

