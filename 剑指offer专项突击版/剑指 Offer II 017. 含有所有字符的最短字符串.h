/**
 * @file 剑指 Offer II 017. 含有所有字符的最短字符串.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。

如果 s 中存在多个符合条件的子字符串，返回任意一个。

 

注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/M1oyTv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <string>
#include <vector>
#include <map>
#include <inttypes.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        map<char, int> cnt;
        int needed = t.size();
        for (char c : t) {
            cnt[c]++;
        }
        int left = 0;
        int right = 0;
        int len = INT32_MAX;
        string res;
        while (right < s.size()) {
            // 右边界进了一个数
            char c1 = s[right];
            if (cnt.find(c1) != cnt.end()) {
                // 如果c1是我们需要的
                if (cnt[c1] > 0) {
                    needed--;
                }
                cnt[c1]--;
            }
            // 如果已经找到了一个字串 尝试移动左边界
            while (needed == 0 && left <= right) {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    res = s.substr(left, right - left + 1);
                }
                char c2 = s[left];
                if (cnt.find(c2) != cnt.end()) {
                    // 我们需要这个c2
                    if (cnt[c2] >= 0) {
                        needed++;
                    }
                    cnt[c2]++;
                }
                left++;
            }
            // 右边界一直向右移动
            right++;
            
        }
        return res;
        
    }
};