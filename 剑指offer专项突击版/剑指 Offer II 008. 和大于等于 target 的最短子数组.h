/**
 * @file 剑指 Offer II 008. 和大于等于 target 的最短子数组.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/2VG8Kg
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
#include <inttypes.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 双指针 滑动窗口
        int left = 0;
        int right = 0;
        // nums[left, right] 的和
        int sum = nums[0];
        int res = INT32_MAX;
        while (right < nums.size()) {
            // 考察以left为头的right能走多远
            if (sum < target) {
                right++;
                if (right == nums.size()) break;
                sum += nums[right];
            } else {
                // 满足条件了 因为只有正数 因此此时是最短的
                res = min(res, right - left + 1);
                // 推动left
                sum -= nums[left++];
            }        
        }
        return res == INT32_MAX ? 0 : res;
    }
};