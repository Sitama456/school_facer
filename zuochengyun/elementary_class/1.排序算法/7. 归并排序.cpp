/**
 * @file 7. 归并排序.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <vector>
using namespace std;
/**
 * 左侧有序， 右侧有序  -> 合并起来有序
 * 
 * 
 */

void merge(vector<int>& nums, int L, int M, int R) {
    vector<int> help(R - L + 1);
    int i = 0;
    int p1 = L;
    int p2 = M + 1;
    while (p1 <= M && p2 <= R) {
        if (nums[p1] < nums[p2]) {
            help[i++] = nums[p1++];
        } else {
            help[i++] = nums[p2++];
        }
    }
    while (p1 <= M) {
        help[i++] = nums[p1++];
    }
    while (p2 <= R) {
        help[i++] = nums[p2++];
    }
    for (size_t i = 0; i < help.size(); ++i) {
        nums[i + L] = help[i]; 
    }

}
void process(vector<int>& nums, int L, int R) {
    if (L == R) {
        return;
    }
    int mid = L + (R - L) / 2;
    // 左侧有序
    process(nums, L, mid);
    // 右侧有序
    process(nums, mid + 1, R);
    // 合并有序
    merge(nums, L, mid, R);

}



void mergeSort(vector<int>& nums) {
    process(nums, 0, nums.size() - 1);
}

/**
 * 复杂度分析:
 * merge时间复杂度 : O(N)
 * process时间复杂度:
 * T(N) = 2T(N / 2) + O(N) 
 * a = 2, b = 2, d = 1
 * log(b, a) == d -> O(N * log(N))
 */

/**
 * 
 * 小和问题：在一个数组中， 每一个数左边比当前数小的数累加起来，叫做这个数的小和。求这个数组的
 *      小和(所有小和累加起来)。
 */
int travesalSmallSum(vector<int>&, int, int);
int mergeSmallSum(vector<int>&, int, int, int);

int getSmallSum(vector<int>& nums) {
    // 右边有多少个数比 nums[i] 大, 就产生多少个小和
    return travesalSmallSum(nums, 0, nums.size() - 1);

}

/**
 * @brief L ~ R 范围内的小和 并且排好序
 * 
 * @param nums 
 * @param L 
 * @param R 
 * @return int 
 */
int travesalSmallSum(vector<int>& nums, int L, int R) {
    if (L == R) {
        return 0;
    }
    int mid = L + (R - L) / 2;
    int leftSum = travesalSmallSum(nums, L, mid);
    int rightSum = travesalSmallSum(nums, mid + 1, R);
    return leftSum + rightSum + mergeSmallSum(nums, L, mid, R);
}

int mergeSmallSum(vector<int>& nums, int L, int M, int R) {
    vector<int> help(R - L + 1);
    int i = 0;
    int p1 = L;
    int p2 = M + 1;
    int result = 0;
    while (p1 <= M && p2 <= R) {
        if (nums[p1] < nums[p2]) {
            // 右组 nums[p2 ~ R] 都比nums[p1]大
            result += nums[p1] * (R - p2 + 1);
            help[i++] = nums[p1++];
        } else { // 注意 若是相等情况时必须先拷贝右组 因为不知道右组还有多少个数比此数大
            // 比如 111247   11356 若是先拷贝左组时 则无法知道还有356比1大
            help[i++] = nums[p2++];
        }
    }
    while (p1 <= M) {
        help[i++] = nums[p1++];
    }
    while (p2 <= R) {
        help[i++] = nums[p2++];
    }
    for (size_t i = 0; i < help.size(); ++i) {
        nums[i + L] = help[i];
    }
    return result;

}
/*
 * 逆序对问题：在一个数组中，左边的数如果比右边的数大，则这两个数构成一个逆序对，请找出所有逆序
 *      对。
 */

// 同小和问题一样解法 

