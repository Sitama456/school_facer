/**
 * @file 1.最大相邻两数差值.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个数组，求如果排序之后。相邻两数的最大插值。要求时间复杂度O(N),
 * 且不能用非基于比较的排序
 * 
 */
#include <vector>
#include <algorithm>
#include <inttypes.h>
using namespace std;

struct buttom {
    bool isValid = false;
    int minValue = 0;
    int maxValue = 0;
};

int getBucketId(long num, long len, long min, long max) {
    return (int)((num - min) * len / (max - min));
}


int lastSubValue(vector<int>& nums) {
    int size = nums.size();
    if (size < 2) {
        return 0;
    }
    // 最大值 最小值
    int minValue = INT32_MAX;
    int maxValue = INT32_MIN;
    for (int i = 0; i < size; ++i) {
        if (minValue > nums[i]) minValue = nums[i];
        if (maxValue < nums[i]) maxValue = nums[i];
    }
    if (minValue == maxValue) {
        return 0;
    }
    // 准备 size + 1 个桶
    vector<buttom> buttoms(size + 1);
    // 用桶将数组等分
    // 必定会有一个空桶 空桶排除了桶内解
    // 即答案必定来自与跨桶 不可能来自桶内数的差值。
    int bid = 0;
    for (int i = 0; i < size; ++i) {
        bid = getBucketId(nums[i], size, minValue, maxValue);
        buttoms[i].minValue = buttoms[i].isValid ? min(buttoms[i].minValue, nums[i]) : nums[i];
        buttoms[i].maxValue= buttoms[i].isValid ? max(buttoms[i].maxValue, nums[i]) : nums[i];
        buttoms[i].isValid = true;   
    }

    int res = 0;
    int lastMax = buttoms[0].maxValue;
    int i = 1;
    for (; i <= size; ++i) {
        if (buttoms[i].isValid) {
            res = max(buttoms[i].minValue - lastMax, res);
            lastMax = buttoms[i].maxValue;
        }

    }

}
