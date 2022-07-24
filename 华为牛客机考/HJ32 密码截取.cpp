/**
 * @file HJ32 密码截取.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
Catcher是MCA国的情报员，他工作时发现敌国会用一些对称的密码进行通信，比如像这些ABBA，ABA，A，123321，但是他们有时会在开始或结束时加入一些无关的字符以防止别国破解。比如进行下列变化 ABBA->12ABBA,ABA->ABAKK,123321->51233214　。因为截获的串太长了，而且存在多种可能的情况（abaaab可看作是aba,或baaab的加密形式），Cathcer的工作量实在是太大了，他只能向电脑高手求助，你能帮Catcher找出最长的有效密码串吗？

数据范围：字符串长度满足 1 \le n \le 2500 \1≤n≤2500 
输入描述：
输入一个字符串（字符串的长度不超过2500）

输出描述：
返回有效密码串的最大长度

示例1
 */

#include <string>
#include <iostream>
#include <vector>
using namespace std;
 
int getMaxLen(string& s);
int main(){
    string inputStr;
    cin >> inputStr;
    cout << getMaxLen(inputStr);
    return 0;
}

// 求最长的回文字串的长度
int getMaxLen(string& s) {
    // 处理字符串
    string str("#");
    for (char c : s) {
        str += c;
        str += "#";
    }
    int len = str.size();
    // Manacher算法
    vector<int> pArr(len, 0); // 回文半径数组
    int R = -1; // 最右回文边界的下一个 有效区域是 R - 1
    int C = -1; // 最右回文边界对应的回文中心
    int maxLen = 0;
    for (int i = 0; i < len; ++i) {
        int i1 = 2 * C - i;
        // 必定是回文 不用验证的区域长度
        pArr[i] = R > i ? min(pArr[i1], R - i) : 1;
        // 需要验证的区域往外扩充
        while (i + pArr[i] < len && i - pArr[i] >= 0) {
            if (str[i + pArr[i]] == str[i - pArr[i]]) {
                pArr[i]++;
            } else {
                break;
            }
        }
        // 是否扩得更大
        if (i + pArr[i] > R) {
            R = i + pArr[i];
            C = i;
        }
        maxLen = max(maxLen, pArr[i]);
    }
    return maxLen - 1;
    
}