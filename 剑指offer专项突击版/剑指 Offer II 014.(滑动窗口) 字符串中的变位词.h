/**
 * @file 剑指 Offer II 014. 字符串中的变位词.h
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
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的某个变位词。

换句话说，第一个字符串的排列之一是第二个字符串的 子串 。
 * 
 */
#include <string>
#include <vector>
#include <map>
#include <inttypes.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        // s1中的字符串
        map<char, int> cnt;
        int needed = 0;
        for (char c : s1) {
            cnt[c]++;
            needed++;
        }
        // 定长滑动窗口
        int left = 0;
        int right = 0;
        while (right < s2.size()) {
            // 窗口右边界进来一个数
            char c1 = s2[right];
            // 如果c1在s1中
            if (cnt.find(c1) != cnt.end()) {
                // 需要一个c1
                if (cnt[c1] > 0) {
                    needed--;
                }
                cnt[c1]--;
            }
            // 窗口左边界需要出去一个数
            int left = right - s1.size();
            if (left >= 0) {
                // 如果出去的数是我们要的
                char c2 = s2[left];
                if (cnt.find(c2) != cnt.end()) {
                    // 注意这里是等号
                    if (cnt[c2] >= 0) {
                        needed++;
                    }
                    cnt[c2]++;
                }       
            }
            // 如果needed等于0 则找到了一个合适的窗口
            if (needed == 0) {
                return true;
            }
            // 窗口享有移动
            ++right;
        }
        return false;

    }
};

/**
 * @brief 76. 最小覆盖子串
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

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

/**
 * @brief 面试题 17.18. 最短超串
 * 假设你有两个数组，一个长一个短，短的元素均不相同。找到长数组中包含短数组所有的元素的最短子数组，其出现顺序无关紧要。

返回最短子数组的左端点和右端点，如有多个满足条件的子数组，返回左端点最小的一个。若不存在，返回空数组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shortest-supersequence-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        if (small.size() > big.size()) {
            return {};
        }
        map<int, int> cnt;
        for (int num : small) {
            cnt[num]++;
        }
        int needed = small.size();
        int left = 0;
        int right = 0;
        int len = INT32_MAX;
        int start = -1;
        int end = -1;
        while (right < big.size()) {
            // 右边界进入的值
            int num1 = big[right];
            // 如果是我们需要的
            if (cnt.find(num1) != cnt.end()) {
                if (cnt[num1] > 0) {
                    needed--;
                }
                cnt[num1]--;
            }
            // 找到一个子数组了 尝试移动左边界
            while (needed == 0 && left <= right) {
                if (len > right - left + 1) {
                    len = right - left + 1;
                    start = left;
                    end = right;
                }
                // 左边界出去的值
                int num2 = big[left];
                if (cnt.find(num2) != cnt.end()) {
                    // 是我们需要的
                    if (cnt[num2] >= 0) {
                        needed++;
                    }
                    cnt[num2]++;
                }
                left++;
            }
            right++;
            
        }
        vector<int> res;
        if (start != -1) {
            res = {start, end};
        }
        return res;
    }
};