/**
 * @file 011.整数对最小和.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125116956
 * 
 */

#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(int i, int j) {
        return i > j;
    }
};

int minSum(vector<int>& arr1, vector<int>& arr2, int k) {
    priority_queue<int, vector<int>, cmp> bigRootHeap; //大根堆
    int len1 = arr1.size();
    int len2 = arr2.size();
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            if (bigRootHeap.size() < k) {
                bigRootHeap.push(arr1[i] + arr2[j]);
            } else {
                int sum = arr1[i] + arr2[j];
                if (sum < bigRootHeap.top()) {
                    bigRootHeap.pop();
                    bigRootHeap.push(sum);
                }
            }
        }
    }
    int res = 0;
    while (!bigRootHeap.empty()) {
        res += bigRootHeap.top();
        bigRootHeap.pop();
    }
    return res;

}