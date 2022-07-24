/**
 * @file 剑指 Offer II 020. 回文子字符串的个数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一个字符串 s ，请计算这个字符串中有多少个回文子字符串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return true;
        int count = 0;
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = true;
            }
        }
        for (int i = size - 2; i >= 0; --i) {
            for (int j = size - 1; j > i; --j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
                count = dp[i][j] ? count + 1 : count;
            }
        }
        // 要加上dp对角元素的true
        return count + size;
    }

    // 动态规划
    // s[i...j]的字串是不是回文串
    bool process(string& s, int i, int j) {
        if (i >= j) {
            return true;
        }
        if (s[i] == s[j]) {
            return process(s, i + 1, j - 1);
        }
        return false;

    }
};