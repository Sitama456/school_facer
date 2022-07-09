/**
 * @file 51.数组中的逆序对.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return process(nums, 0, nums.size() - 1);
    }

    //  L ~ R 范围内的逆序对 并且排好序
    int process(vector<int>& nums, int L, int R) {
        if (L == R) {
            return 0;
        }
        int mid = L + (R - L) / 2;
        int leftPair = process(nums, L, mid);
        int rightPair = process(nums, mid + 1, R);
        // merge时产生的逆序对
        int mergePair = leftPair + rightPair + mergePairs(nums, L, mid, R);
        return mergePair;
    }

    int mergePairs(vector<int>& nums, int L, int M, int R) {
        vector<int> help(R - L + 1);
        int i = 0; 
        int p1 = L;
        int p2 = M + 1;
        int result = 0;
        while (p1 <= M && p2 <= R) {
            // 右边比左边小 产生逆序对
            if (nums[p2] < nums[p1]) {
                result += M - p1 + 1;
                help[i++] = nums[p2++];
            } else { // 注意 如果相等情况下必须先拷贝左组 因为不知道左边还有多少个大于右边这个数 比如
                // 4 7 8    4 5  如果先拷贝的时右组的4 就丢失了左组 7 和 8 比右组 4 大的情况
                help[i++] = nums[p1++];
            }
        }
        while (p1 <= M) {
            help[i++] = nums[p1++];
        }
        while (p2 <= R) {
            help[i++] = nums[p2++];
        } 
        for (int i = 0; i < help.size(); ++i) {
            nums[i + L] = help[i];
        }
        return result;
    }
};