/*
 * @Description: 
 * @Author: mzm
 * @Date: 2022-05-27 23:23:40
 * @LastEditTime: 2022-05-29 08:43:53
 * @LastEditors: mzm
 */
/**
 * @file 5. 二分法.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <vector>
using namespace std;

/**
 * 在有序数组中查找数字是否存在
 * 
 */
int hasNumber(vector<int>& nums, int num) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == num) {
            return mid;
        } else if (nums[mid] < num) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return -1;
}

/**
 * 在有序数组中找 >= num 最左侧的位置
 * 
 */
int leftIndexLargerNumber(vector<int>& nums, int num) {
    int left = 0, right = nums.size() - 1;
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= num) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

// 局部最小问题
/**
 * 数组arr无序，但任意两个相邻数字一定不相等。
 * 局部最小：
 * 1) 0 位置比 1 位置小
 * 2) n - 1 位置比 n - 2 位置小
 * 3) i 位置比 i - 1 位置和 i + 1 位置小
 */
// 返回一个局部最小的数 比 BigO(N) 好的方法 最好二分
int localMinNumber(vector<int>& nums) {
    int size = nums.size();
    if (nums[0] < nums[1]) {
        return nums[0];
    }
    if (nums[size - 1] < nums[size - 2]) {
        return nums[size - 1];
    }
    int left = 0;
    int right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid]) {
            return nums[mid];
        } else if (nums[mid] > nums[mid - 1]) {
            right = mid;
        } else if (nums[mid] > nums[mid + 1]) {
            left = mid + 1;
        }
    }
    return 0;
}