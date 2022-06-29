/**
 * @file 19.正则表达式匹配.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
 * 而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

/**
 * @brief 思路 假设当前来到 i (字符串s) j (正则串p)位置，则正则串 p[j] 有三种情况
 * 1) p[j] 是正常字符，如果 s[i] == s[j] 则看 s[0...i - 1] 与 p[0...j - 1]是否匹配。 否则不匹配
 * 2) p[j] 是 .，则看 s[0...i - 1] 与 p[0...j - 1]是否匹配
 * 3) p[j] 是 *, 则有两种选择 一是匹配 二是不匹配。有一个为true则能够匹配上
 * 
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if (!p.empty() && p[0] == '*') {
            return false;
        }
        return process(s, p, s.size() - 1, p.size() - 1);
    }
    // 匹配 0 ~ i 的字符串 s 和 0 ~ j 的正则串 p
    bool process(string& s, string& p, int i, int j) {
        // 字符串空了
        if (i == -1) {
            // 正则串也空了
            if (j == -1) {
                return true;
            } else {
                // 正则串剩余字符必定是 a*b*c* 的偶数个
                int restp = j - 0 + 1;
                if (restp & 1) return false;
                for (int i = 1; i < restp; i += 2) {
                    if (p[i] != '*') return false;
                }
                return true;
            }
        }
        // 正则串空了 而字符串还有 直接false
        if (j == -1) return false;

        if (p[j] != '*') {
            if (p[j] == s[i] || p[j] == '.') {
                return process(s, p, i - 1, j - 1);
            } else {
                return false;
            }
        } else { // p[j]为* 则看它前一个 主函数需要保证此时 j != 0
            char c = p[j - 1];
            // 如果能够匹配上 则有匹配和不匹配两种选择
            if (c == s[i] || c == '.') {
                // 匹配
                bool selected = process(s, p, i - 1, j);
                // 不匹配
                bool noselected = process(s, p, i, j - 2);
                return selected || noselected;
            } else { // 无法匹配 连选择的机会都没有
                return process(s, p, i, j - 2);
            }
        }
    }
    
    // todo 改动态规划
    bool dpMethod(string& s, string& p) {
        // 考虑 -1 情况 将dp[i][j] 定义为 前s前i个字符串与p前n个字符串匹配
        // 所以在匹配时时 p[i - 1] 和 p[j - 1] 在匹配。
        if (p.empty()) {
            return s.empty() ? true : false;
        }
        int ssize = s.size();
        int psize = p.size();
        vector<vector<bool>> dp(ssize + 1, vector<bool>(psize + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= psize; ++j) {
            if (j & 1) {
                dp[0][j] = false;
            } else {
                dp[0][j] = p[j - 1] == '*' && dp[0][j - 2];
            }
        }
        for (int i = 1; i <= ssize; ++i) {
            dp[i][0] = false;
        }

        for (int i = 1; i <= ssize; ++i) {
            for (int j = 1; j <= psize; ++j) {
                if (p[j - 1] != '*') {
                    if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    char c = p[j - 2];
                    if (c == s[i - 1] || c == '.') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 2];
                    }
                }             
            }
            
        }
        return dp[ssize][psize];
    }
};
