/**
 * @file 53.1.在排序数组中查找数字.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 统计一个数字在排序数组中出现的次数。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int> res = partition(nums, target, 0, nums.size() - 1);
        return res[1] - res[0] - 1;
    }
    vector<int> partition(vector<int>& nums, int target, int L, int R) {
        // 小于区域
        int leftPartition = L - 1;
        // 大于区域
        int rightPartition = R + 1;
        int i = L;
        while (i < rightPartition) {
            if (nums[i] < target) {
                leftPartition++;
                swap(nums[i], nums[leftPartition]);
                i++;
            } else if (nums[i] > target) {
                rightPartition--;
                swap(nums[i], nums[rightPartition]);
            } else {
                i++;
            }
        }
        return {leftPartition, rightPartition};
    }
};