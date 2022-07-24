/**
 * @file 剑指 Offer II 015. 字符串中的所有变位词.h
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
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 变位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

变位词 指字母相同，但排列不同的字符串。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/VabMRr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        int needed = p.size();
        map<char, int> cnt;
        for (char c : p) {
            cnt[c]++;
        }
        int left = 0;
        int right = 0;
        vector<int> res;
        while (right < s.size()) {
            // 右边界进来一个值
            char c1 = s[right];
            // 看是否是我们需要的
            if (cnt.find(c1) != cnt.end()) {
                // 是我们需要的
                if (cnt[c1] > 0) {
                    needed--;
                }
                cnt[c1]--;
            }

            // 左边界出去一个值
            left = right - p.size();
            if (left >= 0) {
                char c2 = s[left];
                if (cnt.find(c2) != cnt.end()) {
                    if (cnt[c2] >= 0) {
                        needed++;
                    }
                    cnt[c2]++;
                }
            }
            if (needed == 0) {
                res.push_back(right - p.size() + 1);
            }
            right++;
        }
        return res;
    }
};