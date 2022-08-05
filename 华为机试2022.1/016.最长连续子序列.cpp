/**
 * @file 016.最长连续子序列.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125130902
 * 
 */
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int maxSubStrSum(vector<int>& arr, int sum) {
    int tmp = 0;
    int res = 0;
    // 记录累加和为k第一次出现的位置
    map<int, int> records;
    records[0] = -1; // 重要 保证 arr[0] == num 是不会被漏掉
    for (int i = 0; i < arr.size(); ++i) {
        tmp += arr[i];
        if (records.find(tmp - sum) != records.end()) {
            res = max(res, i - records[tmp - sum]);
        }
        if (records.find(tmp) == records.end()) {
            // 只有第一次才会更新
            records[tmp] = i;
        }
    }
    return res;
}

int main() {
    string inputStr;
    while (1) {
        vector<int> arr;
        int sum = 0;
        cin >> inputStr;
        cin >> sum;
        char* tmp = strtok((char*)inputStr.data(), ",");
        while (tmp != NULL) {
            arr.push_back(atoi(tmp));
            tmp = strtok(NULL, ",");
        }
        cout << maxSubStrSum(arr, sum) << endl;
    }
}