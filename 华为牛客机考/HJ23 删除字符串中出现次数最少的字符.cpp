/**
 * @file HJ23 删除字符串中出现次数最少的字符.cpp
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
实现删除字符串中出现次数最少的字符，若出现次数最少的字符有多个，则把出现次数最少的字符都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。

数据范围：输入的字符串长度满足 1 \le n \le 20 \1≤n≤20  ，保证输入的字符串中仅出现小写字母
输入描述：
字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。

输出描述：
删除字符串中出现次数最少的字符后的字符串
 */

#include<iostream>
#include<map>
#include<vector>
#include <string>
#include<algorithm>
using namespace std;

string delLeastTimeChar(string& s) {
    int leastTime = 100000;
    vector<int> cnt(26, 0);
    for(char c : s) {
        cnt[c - 'a']++;
    }
    for (int num : cnt) {
        if (num > 0) {
            leastTime = min(leastTime, num);
        }
    }
    string res;
    for (char c : s) {
        if (cnt[c - 'a'] > leastTime) {
            res.push_back(c);
        }
    }
    return res;
    
}

int main(){
    string inputStr;
    while (cin >> inputStr) {
        cout << delLeastTimeChar(inputStr) << endl;
    }
    return 0;
}