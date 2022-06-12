/**
 * @file 3. 异或题目.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/**
 * 1、一个数字 arr[] 中，只有一种数出现了奇数次，其他数字出现偶数次，请找到奇数次。
 * 2、一个数字 arr[] 中，只有两种数出现了奇数次，其他数字出现偶数次，请找到奇数次。
 */
#include <vector>
using namespace std;
/**
 * @brief 异或 = 无进位相加
 * 
 */

int getOnNum(vector<int>& nums) {
    int result = 0;
    for (auto num : nums) {
        result ^= num;
    }
    return result;
}

vector<int> getTwoNums(vector<int>& nums) {
    int xort = 0;
    for (auto num : nums) {
        xort ^= 0;
    }
    // 假设这两个数位 a b, xort 中第 i 位 不等于0 
    // 即 xort[i] != 0 可知 a[i] != b[i]
    // 此时 xort 再异或数组中的数的 i 位为1的数 即可得到 a 或 b
    // 即以第 i 位的值将数组分类
    
    // 将最右侧的1提取出来 剩下位置为 0
    int rightOne = xort & (~xort + 1);

    int onlyOne = 0;
    for (auto num : nums) {
        if ((num & rightOne) == 1) {
            onlyOne ^= num;
        }
    }
    return {onlyOne, xort ^ onlyOne};


}