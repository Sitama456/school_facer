/**
 * @file 030. 字符统计及重排[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125157022
 * 
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> getCountOfChars(string& str) {
    vector<int> count(52, 0);
    for (char c : str) {
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            count[c - 'A' + 26]++;
        }
    }
    return count;
}

int main() {
    string inputStr;
    while (1) {
        cin >> inputStr;
        vector<int> count = getCountOfChars(inputStr);
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] > 0) {
                if (i < 26) {
                    cout << ('a' + i) << ":" << count[i] << ";";
                } else {
                    cout << ('A' + i - 26) << ":" << count[i] << ";";
                }
            }
        }
        
    }
}