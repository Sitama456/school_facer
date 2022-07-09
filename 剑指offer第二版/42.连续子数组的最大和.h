/**
 * @file 42.连续子数组的最大和.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。
 * 
 */
#include <vector>
#include <inttypes.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int count = 0;
        // int res = INT_MIN;
        // for (int i = 0; i < nums.size(); ++i) {
        //     count += nums[i];
        //     if (count > res) {
        //         res = count;
        //     }
        //     // 如果连续和已经为负数了 则更新起始位置 因为复数再加一个数肯定是拉低的
        //     if (count < 0) {
        //         count = 0;
        //     }
        // }
        // return res;
        int res = INT32_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            res = max(process(nums, i), res);
        }
        return res;
    }

    // 动态规划 以 i 为结尾的最大连续子数组的和
    // 以某个数作为结尾，意思就是这个数一定会加上去，那么要看的就是这个数前面的部分要不要加上去。大于 零就加，小于零就舍弃
    int process(vector<int>& nums, int i) {
        if (i == 0) {
            return nums[0];
        }
        int sum = max(process(nums, i - 1) + nums[i], nums[i]);
        return sum;
    }

    // todo 改动态规划

    
};