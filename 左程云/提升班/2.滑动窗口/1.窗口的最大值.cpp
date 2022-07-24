/**
 * @file 1.窗口的最大值.cpp
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
 * 有一个整型数组arr和一个大小位w的窗口从数组的最左边滑到最右边，窗口每次向右滑动
 * 一格，求窗口的最大值数组
 * 
 * 窗口左右边界L R。 L 不要超过 R。R往右动，则有一个数进入到窗口了。L往右动，
 * 则有一个数要出窗口。每次都可以让L动或者R动
 */

#include <vector>
#include <deque>
using namespace std;

vector<int> getMaxNumVec(vector<int>& nums, int k) {
    int size = nums.size();
    if (k == 0 && k > size) return {};

    vector<int> res(size - k + 1);
    int right = 0;
    int count = 0;
    deque<int> window;
    while (right < size)
    {
        // 进来一个数
        int num = nums[right];
        while(!window.empty() && num > window.back()) {
            window.pop_back();
        }
        window.push_back(right);
        // 左边过期
        if (window.front() == right - k) {
            window.pop_front();
        }
        // 窗口形成了
        if (right >= k - 1) {
            res[count++] = nums[window.front()];
        }
    }
    return res;
}
