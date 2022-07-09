/**
 * @file 56.2.数组中数字出现的次数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 统计每个位上出现1的个数 再 %3 即可得到出现一次1的位
        vector<int> bit(32, 0);
        for (int num : nums) {
            for (int j = 0; j < 32; ++j) {
                if (num & 1 << j) {
                    bit[j]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (bit[i] % 3) {
                res |= (1 << i);
            }
        }
        return res;
    }
};