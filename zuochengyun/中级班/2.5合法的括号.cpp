/**
 * @file 2.5合法的括号.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 一个合法的括号匹配序列有以下定义
 * 1) 空串 "" 是一个合法的括号匹配序列
 * 2) 如果"X"和"Y"都是合法的括号匹配序列，"XY"合法
 * 3) 如果"X"合法，则"(X)"也合法
 * 4) 每个合法的括号序列都可以由以上规则生成
 * 
 * 对于一个合法的括号序列，可以定义其深度：
 * 1) 空串""深度为0
 * 2) 如果"X"深度为x,那么字符串"(X)"深度为x+1
 * 
 *原题: 给定一个合法括号序列 计算其深度
 * 
 */

#include <string>
using namespace std;

int maxDeep(string& str) {
    int res = 0;
    int count = 0;
    for (auto c : str) {
        if (c == '(') {
            count++;
            res = res > count ? res : count;
        } else {
            count--;
        }

    }
    return res;
}
#include <vector>
/**
 * @brief 加题:
 * 给定一个括号串，请返回最长有效括号子串的长度 
 * 
 * 求字串 子数组之类的问题，表示连续的，以每个位置为结尾的情况下，答案是多少
 * 
 */
int maxLength(string str) {
    if (str.empty()) {
        return 0;
    }

    int size = str.size();
    // 以 i 位置为结尾的有效括号串长度
    vector<int> dp(size);
    int pre = 0;
    int res = 0;
    for (int i = 1; i < size; ++i) {
        // 只有右括号结尾才可能有效
        if (str[i] == ')') {
            // 与 str[i]配对的左括号的位置 比如
            // ( (())() ) i = 7 dp[i - 1] = 6 pre = 7 - 6 - 1 = 0
            // 
            pre = i - dp[i - 1] - 1;
            if (pre >= 0 && str[pre] == '(') {
                dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
    
}