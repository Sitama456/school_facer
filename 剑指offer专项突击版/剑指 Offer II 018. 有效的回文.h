/**
 * @file 剑指 Offer II 018. 有效的回文.h
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
 * 给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。

本题中，将空字符串定义为有效的 回文串 。
 */
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        string tmp("#");
        for (char c : s) {
            if (isValid(c)) {
                tmp.push_back(c);
                tmp += "#";
            }
        }
        int size = tmp.size();
        int left = size / 2 - 1;
        int right = size / 2 + 1;
        while (left >= 0 && right < size) {
            if (tmp[left] != tmp[right]) return false;
            left--;
            right++;
        }
        return true;
    }

    bool isValid(char& c) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z');     
    }
    
};