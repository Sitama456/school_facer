/**
 * @file 剑指 Offer II 010. 和为 k 的子数组.h
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
 * 给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。
 * 
 */
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 生成包含当前位置的前缀和
        // 前缀和 -> 索引个数
        map<int, int> sums;
        // 累加和为0的位置是-1 保证num[0] = k 是被考察到
        sums[0] = 1;
        int sum = 0;
        int count = 0;
        // 以 i 位置为结尾的子数组个数
        // sums[i] - sums[j] = nums[i] + nums[i - 1] + ... + nums[j + 1] = k
        // sums[j] = sums[i] - k
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i]; // sum[i]
            if (sums.find(sum - k) != sums.end()) {
                count += sums[sum - k];
            }
            sums[sum]++;
        }
        return count;
        
    }
};