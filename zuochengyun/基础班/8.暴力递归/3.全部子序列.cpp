/**
 * @file 3.全部子序列.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// 从 res 的角度出发 当前位置要 str 上的哪个字符
void process(string& str, int startIndex, string& res) {

    cout << res << endl;
    if (startIndex == str.size()) {
        return;
    }
    // 当前位置要 i 位置的字符 前面要过的就不再要
    for (int i = startIndex; i < str.size(); ++i) {
        res.push_back(str[i]);
        process(str, i + 1, res);
        res.pop_back();
    }
}

void printAllSubArray(string str) {
    string res;
    process(str, 0, res);
}