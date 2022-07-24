/**
 * @file 剑指 Offer II 032. 有效的变位词.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定两个字符串 s 和 t ，编写一个函数来判断它们是不是一组变位词（字母异位词）。

注意：若 s 和 t 中每个字符出现的次数都相同且字符顺序不完全相同，则称 s 和 t 互为变位词（字母异位词）。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/dKk3P7
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        stack<char> st;
        vector<int> cnt(26, 0);
        for (char c : s) {
            st.push(c);
            cnt[c - 'a']++;
        }
        for (int i = t.size() - 1; i >= 0; --i) {
            cnt[t[i] - 'a']--;
            if (t[i] == st.top()) {
                st.pop();
            }
        }
        for (int num : cnt) {
            if (num != 0) {
                return false;
            }
        }
        return !st.empty();
    }
};