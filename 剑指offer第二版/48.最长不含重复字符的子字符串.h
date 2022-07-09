/**
 * @file 48.最长不含重复字符的子字符串.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 * 
 */
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return lengthOfLongestSubstring2(s);
    }

    // 动态规划
    int lengthOfLongestSubstring1(string s) {
        if (s.empty()) return 0;
        // 以 i 位置为结尾的最长无重复字符字串
        int size = s.size();
        vector<int> dp(size);
        dp[0] = 1;
        map<char, int> pos;
        pos[s[0]] = 0;
        int res = 1;
        for (int i = 1; i < size; ++i) {
            int prePos = pos.find(s[i]) == pos.end() ? -1 : pos[s[i]];
            pos[s[i]] = i;
            dp[i] = min(i - prePos, dp[i - 1] + 1);
            res = max(res, dp[i]);
        }
        return res;
    }

    // 双指针
    int lengthOfLongestSubstring2(string s) {
        if (s.empty()) return 0;
        // 左指针 即重复元素之前的位置
        int i = -1;
        int j = 0;
        map<char, int> pos;
        int res = 0;
        while (j < s.size()) {
            if (pos.find(s[j]) != pos.end()) {             
                i = max(i, pos[s[j]]);
            }
            res = max(res, j - i);
            pos[s[j]] = j;
            j++;
        }
        return res;
    }
};