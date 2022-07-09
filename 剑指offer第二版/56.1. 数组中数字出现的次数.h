/**
 * @file 56.1. 数组中数字出现的次数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int rest = 0;
        // 异或操作 无进位相加
        for (auto num : nums) {
            rest ^= num;
        }
        // 取出rest最后一个非0位作为标志
        int flag = rest & (~(rest - 1));
        // 假设 a b 为只出现一次的数
        // flag 将所有数分成两个组 并且 a b不在同一个组
        int num1 = 0;
        for (auto num : nums) {
            if (num & flag) {
                num1 ^= num;
            }
        }
        int num2 = rest ^ num1;
        return { num1, num2 };
    }
};