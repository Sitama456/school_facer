/**
 * @file 剑指 Offer II 004. 只出现一次的数字.h
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
 * 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
 */
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        for (auto num : nums) {
            for (int i = 0; i < 32; ++i) {
                if (num & (1 << i)) {
                    bits[i]++;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < 32; ++i) {
            if (bits[i] % 3) {
                ret |= (1 << i);
            }
        }
        return ret;
    }
};