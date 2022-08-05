/**
 * @file 5.华为机试：整数最小和.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 100分】整数最小和 [ 100 / 中等 ]

整数最小和
题目描述：
输入字符串s，输出s中包含所有整数的最小和

说明：
字符串s，只包含 a-z A-Z ± ；

合法的整数包括

1） 正整数 一个或者多个0-9组成，如 0 2 3 002 102

2）负整数 负号 - 开头，数字部分由一个或者多个0-9组成，如 -0 -012 -23 -00023

输入描述：
包含数字的字符串

输出描述：
所有整数的最小和

示例 1：
输入
bb1234aa
1
输出
10
1
说明
1+2+3+4=10
1
示例 2：
输入
bb12-34aa
1
输出
-31
1
说明
1+2+（-34） = 31
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124038643
 */

/**
 * @brief 遇到负号是 将后续数字字符当成一个整体，否则就是一个个字符
 * 
 */
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

bool isEnglishLetters(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

bool isPosNegLeggers(char c) {
    return c == '+' || c == '-';
}

int getMinValue(string str) {
    int len = str.size();
    if (str.empty()) return 0;
    if (len == 1) {
        if (str[0] == '+' || str[0] == '-') return 0;
    }
    int res = 0;
    bool neg = str[0] == '-' ? true : false;
    if (neg) {
        int num = atoi(str.substr(1).c_str());
        res = -num;
    } else {
        for (char c : str) {
            if (isdigit(c)) {
                res += c - '0';
            }
        }
    }
    return res;
}

int minSum(string& str) {
    int len = str.size();
    int res = 0;
    bool negFlag = false; // 出现负数
    string tmps;
    for (char c : str) {
        if (c >= '0' && c <= '9') {
            // 如果是负数状态 则加入到tmps中
            if (negFlag) {
                tmps.push_back(c);
            } else {// 正数状态 直接相加
                res += c - '0';
            }
        } else if (c == '-') {
            // 如果是负数状态 证明前一个负数以及结束了
            if (negFlag) {
                res -= atoi(tmps.c_str());
                tmps.clear();
            }
            negFlag = true;
        } else {
            // 其他字符 负数状态结束
            negFlag = false;
            res -= atoi(tmps.c_str());
            tmps.clear();
        }
    }
    if (negFlag) {
        res -= atoi(tmps.c_str());
    }
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        cout << minSum(inputStr) << endl;
    }
    return 0;
} 