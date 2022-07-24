/**
 * @file 剑指 Offer II 019. 最多删除一个字符得到回文.h
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
 * 给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。
 */
#include <string>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() <= 1) return true;
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right]) {
                // 删除left字符 或者right字符
                return check(s, left + 1, right) || check(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }

    bool check(string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};