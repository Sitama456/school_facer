/**
 * @file HJ4 字符串分隔.cpp
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
 * warning 校招时部分企业笔试将禁止编程题跳出页面，为提前适应，练习时请使用在线自测，而非本地IDE。
描述
•输入一个字符串，请按长度为8拆分每个输入字符串并进行输出；

•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述：
连续输入字符串(每个字符串长度小于等于100)

输出描述：
依次输出所有分割后的长度为8的新字符串
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;



vector<string> splitStr(string& str) {
    vector<string> res;
    int size = str.size();
    int cnt = size / 8;
    int rest = size % 8;
    for (int i = 0; i < cnt; ++i) {
        res.push_back(str.substr(i * 8, 8));
    }
    if (rest) {
        res.push_back(str.substr(cnt * 8, rest));
        for (int i = 0; i < 8 - rest; ++i) {
            res[res.size() - 1].push_back('0');
        }
    }
    return res;
    
    
}

int main() {
    string str;
    cin >> str;
    vector<string> res = splitStr(str);
    for (string& s : res) {
        cout << s << endl;
    }
    return 0;
}