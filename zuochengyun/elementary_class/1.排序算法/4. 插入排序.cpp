/**
 * @file 4. 插入排序.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-27
 * 
 * @copyright Copyright (c) 2022
 * 
 * 0 ~ i - 1 位置有序，i 位置再往前交换 是的 0 ~ i 位置有序
 * 
 */

#include <vector>
using namespace std;

void insertSort(vector<int>& nums) {
    int size = nums.size();
    if (size < 2) {
        return;
    }

    for (size_t i = 1; i < size; ++i) {
        int j = i;
        while (nums[j] < nums[j - 1] && j >= 1) {
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
    return ;
}