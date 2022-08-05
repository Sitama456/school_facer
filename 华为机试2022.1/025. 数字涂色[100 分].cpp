/**
 * @file 025. 数字涂色[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125155708
 * 暴力解法 每一个都去尝试
 */
#include <vector>
#include <algorithm>
using namespace std;
int minColorKind(vector<int>& nums) {
    sort(nums.begin(), nums.end()); 
    int size = nums.size();
    vector<bool> flags(size, false); // 是否上色
    int res = 0;
    // 遍历
    for (int i = 0; i < size; ++i) {
        if (flags[i]) {
            continue;
        }
        // 当前数字能给多少个数字上色
        for (int j = i; j < size; ++j) {
            if (nums[j] % nums[i] == 0) {
                flags[j] = true;
            } 
        }
        // 颜色+1
        res++;
    }
    return res;
}