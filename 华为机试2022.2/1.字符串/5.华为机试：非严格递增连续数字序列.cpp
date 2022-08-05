/**
 * @file 5.华为机试：非严格递增连续数字序列.cpp
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
 * 非严格递增连续数字序列
题目描述：
输入一个字符串仅包含大小写字母和数字，求字符串中包含的最长的非严格递增连续数字序列的长度（比如12234属于非严格递增连续数字序列）。

输入描述:
输入一个字符串仅包含大小写字母和数字，输入的字符串最大不超过255个字符。

输出描述：
最长的非严格递增连续数字序列的长度

示例 1：

输入
abc2234019A334bc
1
输出
4
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123930773
 */
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief 仅包含数字的最长非严格递增子序列长度
 * 
 * @param str 
 * @return int 
 */
int maxLenOfNumStrs(string str) {
    int res = 0;
    int count = 1;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] >= str[i - 1]) {
            count++;
            res = max(res, count);
        } else {
            count = 1;
        }
    }
    return res;
}

int maxLen(string& str) {
    int len = str.size();
    int res = 0;
    int i = 0;
    // 跳过开头
    while (i < len && !isdigit(str[i])) {
        i++;
    }
    int j = i;
    while (i < len) {
        // 跳过数字部分
        while (i < len && isdigit(str[i])) {
            i++;
        }
        res = max(res, maxLenOfNumStrs(str.substr(j, i - j)));
        // 跳过非数字部分
        while (i < len && !isdigit(str[i])) {
            i++;
        }
        j = i;
    }
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        cout << maxLen(inputStr) << endl;
    }
    return 0;
}