/**
 * @file 59.1. 滑动窗口的最大值.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
 * 
 */
#include <deque>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty() || k < 1 || k > nums.size()) {
            return res;
        }
        res.resize(nums.size() - k + 1);
        int index = 0;
        deque<int> qmax;
        for (int i = 0; i < nums.size(); ++i) {
            // 如果双端队列为空并且尾部元素较小 就一直弹出
            // 维护一个从队首到队尾递减的队列
            while(!qmax.empty() && nums[qmax.back()] < nums[i]) {
                qmax.pop_back();
            }
            qmax.push_back(i);
            // 如果因为队列移动的时候弹出的是队首 
            if (i - k == qmax.front()) {
                qmax.pop_front();
            }
            if (i >= k - 1) res[index++] = nums[qmax.front()];
        }
        return res;
    }
};