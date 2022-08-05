/**
 * @file 014.求满足条件的最长子串的长度.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125130632
 * 
 */
#include <string>
#include <iostream>
using namespace std;

bool isEngChar(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

/**
 * @brief 以 i 位置结尾的最长合法字串长度
 * 
 * @param str 
 * @param i 
 * @param preEngChar  上一次字母出现的位置 
 * @return int -1 全是字母 -2 全是数字
 */
int maxLenSubStr(string& str, int i, int preEngChar) {
    if (i == 0) {
        return isEngChar(str[i]) ? -1 : -2;
    }

    // 前一个字串
    int preLen = maxLenSubStr(str, i - 1, preEngChar);
    // 如果全是字母
    if (preLen == -1) {
        return isEngChar(str[i]) ? -1 : 2;
    }
    // 如果全是数字
    if (preLen == -2) {
        return isEngChar(str[i]) ? i + 1 : -2;
    }
    // 正常情况
    if (isEngChar(str[i])) {
        return i - preEngChar;
    }

    return preLen + 1;

}

int main() {
    while (1) {
        string inputStr;
        cin >> inputStr;
        int len = inputStr.size();
        int preEngChar = -1;
        int res = 0;
        for (int i = 0; i < len; ++i) {
            int len = maxLenSubStr(inputStr, i, preEngChar);
            res = max(res, len);
            if (isEngChar(inputStr[i])) {
                preEngChar = i;
            }

        }
        cout << res << endl;

    }
}