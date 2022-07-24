/**
 * @file 剑指 Offer II 005. 单词长度的最大乘积.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一个字符串数组 words，请计算当两个字符串 words[i] 和 words[j] 不包含相同字符时，它们长度的乘积的最大值。假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串，返回 0。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/aseY1I
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        vector<int> bits(size, 0); // 去重判断
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                bits[i] |= (1 << (words[i][j] - 'a'));
            }
        }

        int res = INT_MIN;
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (!(bits[i] & bits[j])) {
                    int multSize = words[i].size() * words[j].size();
                    res = max(res, multSize);
                }
            }
        }
        return res == INT_MIN ? 0 : res;
    }
};