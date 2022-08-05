/**
 * @file 022. 用连续自然数之和来表达整数[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125155159
 * 
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
/**
 * @brief 转换为子序列之和为n的问题
 */
vector<vector<int>> getSubArr(int n) {
    int right = 1;
    int left = 1;
    int sum = 0;
    vector<int> tmp;
    vector<vector<int>> res;
    while (right <= n) {
        // 如果和小于n 则要持续进来数字
        while (right <= n && sum < n) {
            sum += right;
            right++;
        }
        // 如果是大于情况 左边界往右移动
        if (sum > n) {
            sum -= left;
            left++;
        }
        // 到这里再判断相等情况 否则会漏掉一些情况
        if (sum == n) {
            tmp.clear();
            for (int i = left; i < right; ++i) {
                tmp.push_back(i);
            }
            res.push_back(tmp);
            sum -= left++;
        } 
    }
    return res;
}

int main() {
    int n = 0;
    while (1) {
        cin >> n;
        vector<vector<int>> res = getSubArr(n);
        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < res[i].size(); ++j) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
}