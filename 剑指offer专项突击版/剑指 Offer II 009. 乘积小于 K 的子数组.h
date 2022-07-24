/**
 * @file 剑指 Offer II 009. 乘积小于 K 的子数组.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一个正整数数组 nums和整数 k ，请找出该数组内乘积小于 k 的连续的子数组的个数。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int mult = 1;
        int left = 0;
        int right = 0;
        int count = 0;
        // 以right为结尾的子数组 满足条件的个数
        for (; right < nums.size(); ++right) {
            mult *= nums[right];
            while (mult >= k) {
                mult /= nums[left++];
            }
            // 找到最左满足条件的左边界
            count += right - left + 1;
        }
        return count;
    }
};