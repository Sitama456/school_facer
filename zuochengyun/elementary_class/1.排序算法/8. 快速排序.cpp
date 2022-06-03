/*
 * @Description: 
 * @Author: mzm
 * @Date: 2022-05-29 10:15:24
 * @LastEditTime: 2022-05-29 11:49:44
 * @LastEditors: mzm
 */

#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;
/**
 * 荷兰国旗问题：
 * 1) 给定一个数组arr, 和一个数num, 请把小于等于num的数放在数组左边，大于num的数放在数组右边。
 *      要求额外空间复杂度O(1), 时间复杂度O(N)
 * 2) 给定一个数组arr, 和一个数num, 请把小于num的数放在数组左边， 等于num的数放在数组中间，
 *      大于num的数放在数组右边。要求额外空间复杂度O(1), 时间复杂度O(N)
 * 
 */

// 规定一个小于等于区域 一开始为 0 
// <= num | nums
int dutchFlag1(vector<int>& nums, int target, int L, int R) {
    int partition = -1;
    for (size_t i = L; i <= R; ++i) {
        if (nums[i] <= target) {
            swap(nums[i], nums[partition + 1]);
            partition++;
        }
    }
    return partition;
}

vector<int> dutchFlag2(vector<int>& nums, int target, int L, int R) {
    // 小于区域
    int leftPartition = -1;
    // 大于区域
    int rightPartion = nums.size();
    int i = L;
    while (i <= R) {
        if (nums[i] < target) {
            swap(nums[leftPartition + 1], nums[i]);
            leftPartition++;
            i++;
        } else if (nums[i] > target) {
            swap(nums[rightPartion - 1], nums[i]);
            rightPartion--;
        } else {
            i++;
        }
    }
    return {leftPartition, rightPartion};
}
/**
 * @brief 快速排序
 * 
 * @param nums 
 */
void processQuickSort1(vector<int>& nums, int L, int R);
void quickSort1(vector<int>& nums) {
    processQuickSort1(nums, 0, nums.size() - 1);
}

void processQuickSort1(vector<int>& nums, int L, int R) {
    // 拿最后一个数划分
    int partition = dutchFlag1(nums, nums[R], L, R - 1);
    processQuickSort1(nums, L, partition);
    processQuickSort1(nums, partition + 2, R);
}


void processQuickSort2(vector<int>& nums, int L, int R);
void quickSort2(vector<int>& nums) {
    processQuickSort2(nums, 0, nums.size() - 1);
}

void processQuickSort2(vector<int>& nums, int L, int R) {
    vector<int> partition = dutchFlag2(nums, nums[R], L, R);
    processQuickSort2(nums, L, partition[0]);
    processQuickSort2(nums, partition[1], R);
}

// 随机取一个数值作为划分标准
void processQuickSort3(vector<int>& nums, int L, int R);
void quickSort3(vector<int>& nums) {
    srand(time(nullptr));
    processQuickSort2(nums, 0, nums.size() - 1);
}

void processQuickSort3(vector<int>& nums, int L, int R) {
    int randIndex = rand() % (R - L + 1) + L;
    swap(nums[randIndex], nums[R]);
    vector<int> partition = dutchFlag2(nums, nums[R], L, R);
    processQuickSort3(nums, L, partition[0]);
    processQuickSort3(nums, partition[1], R);
    
}