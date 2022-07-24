/**
 * @file 2.2添加括号.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个只含有左括号和右括号的字符串，请判断要添加多少个括号让整体完整
 * 
 */
#include <string>
#include <vector>
using namespace std;

int needParentheses(string& str) {
    int count = 0; // 需要的右括号个数
    int ans = 0; // 需要的左括号个数
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            count++;
        } else {
            if (count == 0) {
                ans++;
            } else {
                count--;
            }
        }
    }
    return ans + count;
}