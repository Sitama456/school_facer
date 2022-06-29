/**
 * @file 21.调整数组顺序使奇数位于偶数前面.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
 * 
 */

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int p = 0;
        int q = nums.size() - 1;
        while (p < q) {
            if ((nums[p] & 1) && (nums[q] & 1)) {
                p++;
            } else if ((nums[p] & 1) && !(nums[q] & 1)) { // 左奇右偶
                q--;
            } else if (!(nums[p] & 1) && !(nums[q] & 1)) { // 左偶右偶
                q--;
            } else { // 左偶右奇
                swap(nums[p], nums[q]);
                p++;
                q--;
            }
            
        }
        return nums;
    }
};