/**
 * @file 剑指 Offer II 011. 0 和 1 个数相同的子数组.h
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
 * 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 将0变成-1 求累加和为0的最长连续字串
        for (int& num : nums) {
            if (num == 0) {
                num = -1;
            }
        }
        // 记录第一次出现的累加和出现的索引
        // 累加和->索引
        unordered_map<int, int> sums;
        // 累加和为0的索引时-1
        // 为了不漏掉nums[0] == 0 时的情况
        sums[0] = -1;
        // 考察以i位置结尾的最长连续字串
        // sums[i] - sums[j] = nums[i] + nums[i - 1] +...+nums[j + 1] = k
        // sums[j] = sums[i] - k
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sums.find(sum - 0) != sums.end()) {
                res = max(res, i - sums[sum - 0]);
            } 
            // 只记录最早出现的那次的位置
            if (sums.find(sum) == sums.end()) {
                sums[sum] = i;
            }
        }
        return res;
    }

   
};