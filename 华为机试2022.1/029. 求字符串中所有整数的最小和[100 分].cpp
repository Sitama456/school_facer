/**
 * @file 029. 求字符串中所有整数的最小和[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125156980
 * 
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int minSum(string& str) {
    int res = 0;
    int i = 0;
    int len = str.size();
    for (; i < len; ++i) {
        // 如果当前为负数
        if (str[i] == '-') {
            int j = i;
            // 尽可能地囊括数字进来
            while (i + 1 < len && isdigit(str[i + 1])) {
               i++;
            }
            res -= atoi(str.substr(j + 1, i - j).c_str());
        } else if (isdigit(str[i])) {
            res += str[i] - '0';
        }
    }
    return res;
}

int main() {
    string inputStr;
    while (1) {
        cin >> inputStr;
        cout << minSum(inputStr) << endl;
    }
}