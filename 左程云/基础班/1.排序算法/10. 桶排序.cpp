/*
 * @Description: 
 * @Author: mzm
 * @Date: 2022-05-29 16:22:38
 * @LastEditTime: 2022-05-29 17:02:18
 * @LastEditors: mzm
 */

#include <vector>
using namespace std;
/**
 * @brief 获取第 d 位的数字
 * 
 * @param num 
 * @param d 
 * @return int 
 */
int getDigit(int num, int d) {
    for (int i = 1; i < d; ++i) {
        num /= 10;
    }
    return num % 10;
}
/**
 * @brief 基数排序
 * 
 * @param nums 
 * @param L 
 * @param R 
 * @param digit nums数组中最大的位数 个位 十位 百位...
 */
void radixSort(vector<int>& nums, int L, int R, int digit) {
    int radix = 10;
    int i = 0, j = 0;
    vector<int> help(R - L + 1);
    for (int d = 1; d <= digit; d++) { // 有多少位就进出多少次桶
        // count[0] 当前位(d位)是0的数字有多少个
        // count[1] 当前位(d位)是1的数字有多少个
        // count[2] 当前位(d位)是2的数字有多少个
        // count[3] 当前位(d位)是3的数字有多少个
        vector<int> count(radix);
        for (i = L; i <= R; ++i) {
            j = getDigit(nums[i], d);
            count[j]++; 
        }
        // 处理成前缀和 含义改为
        // count[0] 当前位(d位)小于等于0的数字有多少个
        // count[1] 当前位(d位)小于等于1的数字有多少个
        // ...
        for (int i = 1; i < radix; ++i) {
            count[i] = count[i] + count[i - 1];
        }
        // 入桶
        for (i = R; i >= L; --i) {
            int j = getDigit(nums[i], d);
            help[count[d] - 1] = nums[i];
            count[j]--;
        }
        // 出桶
        for (i = L; i <= R; ++i) {
            nums[i] = help[i];
        }
    }

}

