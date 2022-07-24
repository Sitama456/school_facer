/**
 * @file 剑指 Offer II 016. 不含重复字符的最长子字符串.h
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
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长连续子字符串 的长度。
 */
#include <string>
#include <set>
#include <inttypes.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int res = INT32_MIN;
        // 字符 -> 前一次出现的索引
        set<char> in;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            // 右边进来一个数
            char c1 = s[right];
            // 如果这个数重复了
            // 移动左指针一直弹出到不重复为止
            while (in.find(c1) != in.end() && left <= right) {
                char c2 = s[left];
                in.erase(c2);
                left++;
            }
            res = max(res, right - left + 1);
            // 移动右指针
            in.insert(c1);
            right++;         
        }
        return res;

    }
};