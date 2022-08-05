/**
 * @file 019.数据分类.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125133621
 * 
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int getByteSum(int num) {
    int mask = 0xff;
    int res = 0;
    while (num) {
        res += num & mask;
        num >= 8;
    }
    return res;
}

int validDataNum(vector<int>& nums, int b, int c) {
    int res = 0;
    for (int num : nums) {
        int byteSum = getByteSum(num);
        if (byteSum % b < c) {
            res++;
        }
    }
    return res;
}

int main() {
    int b, c;
    while (1) {
        cin >> c;
        cin >> b;
        vector<int> nums;
        int tmp = 0;
        while (cin >> tmp) {
            nums.push_back(tmp);
        }
        cout << validDataNum(nums, b, c) << endl;
    }
}