/**
 * @file HJ13 句子逆序.cpp
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
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”

所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符

数据范围：输入的字符串长度满足 1 \le n \le 1000 \1≤n≤1000 

注意本题有多组输入
输入描述：
输入一个英文语句，每个单词用空格隔开。保证输入只包含空格和字母。

输出描述：
得到逆序的句子
 */

#include<iostream>
#include<string>
#include <string.h>
#include <vector>
using namespace std;


void reverse(vector<string>& strs) {
    int i = 0;
    int j = strs.size() - 1;
    while (i <= j) {
        swap(strs[i], strs[j]);
    }
}

vector<string> spilit(char* s) {
    vector<string> strs;
    char* s1 = strtok(s, " ");
    while (s1 != NULL) {
        strs.push_back(s1);
        s1 = strtok(NULL, " ");
    }
    return strs;
}

int main(){
    char s[1001];
    cin.getline(s, 1001);
    string ss = s;
    int i = ss.size() - 1;
    int j = i;
    while (i >= 0) {
        // 找到第一个空格
        while (i >= 0 && ss[i] != ' ') {
            i--;
        }
        cout << ss.substr(i + 1, j - i);
        cout << ' ';
        // 跳过空格
        while (i >= 0 && ss[i] == ' ') {
            i--;
        }
        j = i;
    }
    return 0;
   
}
