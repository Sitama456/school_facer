/**
 * @file 50.第一个只出现一次的字符.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
 * 
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        char ret = ' ';
        if (s.empty()) return ret;
        vector<int> timers(26, 0);
        for (auto c : s) {
            timers[c - 'a']++;
        }
        for (auto c : s) {
            if (timers[c - 'a'] == 1) {
                return c;
            }
        }
        return ret;
        

    }
};