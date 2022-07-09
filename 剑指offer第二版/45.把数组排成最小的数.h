/**
 * @file 45.把数组排成最小的数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 
 */
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:

    // 贪心策略 a b < b a 则 a 在前面
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comparator);
        string ret;
        for (auto num : nums) {
            ret += to_string(num);
        }
        return ret;
    }
    // 转换字符串到数字 不足len则补0
    static long getStringNum(string s, int len) {
        int size = s.size();
        int off = len - size;
        long ret = 0;
        for (int i = size - 1; i >= 0; --i) {
            ret +=  (long)(s[i] - '0') * pow(10, off);
            off++;
        }
        return ret;
    }

    // 比较器 
    // true : o1 在 o2 前面
    // false : o2 在 o1 前面
    static bool comparator(int x, int y) {
        // 比较长短
        string tmp1 = to_string(x) + to_string(y);
        string tmp2 = to_string(y) + to_string(x);
        int len = tmp1.size();
        long num1 = getStringNum(tmp1, len);
        long num2 = getStringNum(tmp2, len);
        return num1 < num2;
    }
};