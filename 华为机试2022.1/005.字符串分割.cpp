/**
 * @file 005.字符串分割.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125113220
 */
#include<string.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
bool isSpilitChar(char c) {
    return c == '-';
}


void process(string str) {
    int len = str.size();
    int smallCount = 0;
    for (char c : str) {
        if (c >= 'a' && c <= 'z') {
            smallCount++;
        }
    }
    if (smallCount == len / 2 && len % 2 || smallCount < len) { // 奇数
        // 大写字母较多
        for (char& c : str) {
            if (c >= 'a' && c <= 'z') {
                c = c -'a' + 'A';
            }
        }
    } else if (smallCount > len) {
        // 小写字母多
        for (char& c : str) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'Z';
            }
        }
    }
    cout << str;
}

void spilit(string& str) {
    int i = 0;
    int len = str.size();
    while (i < len && !isSpilitChar(str[i])) {
        i++;
    }
    cout << str.substr(0, i);
    while (isSpilitChar(i)) {
        i++;
    }
    int j = i;
    string all;
    while (i < len) {
        while (i < len && !isSpilitChar(str[i])) {
            i++;
        }
        all += str.substr(j, i - j);
        while (i < len && isSpilitChar(str[i])) {
            i++;
        }
        j = i;
    }
    int count = 0;
    for (int k = 0; k < len; k += 3) {
        cout << '-';
        process(all.substr(k, 3));
    }
    return;

}