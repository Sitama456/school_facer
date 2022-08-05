/**
 * @file 017.事件推送.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125132513
 * 
 */

// 暴力解法
#include <vector>
using namespace std;

vector<int> leastDistance(vector<int>& A, vector<int>& B, int R) {
    int start = 0;
    int lenA = A.size();
    int lenB = B.size();
    vector<int> res;
    for (int i = 0; i < lenA; ++i) {
        while (start < lenB && B[start] < A[start]) {
            ++start;
        }
        if (start == lenB) {
            break;
        }
        for (int j = start; j < lenB; ++j) {
            if (B[j] - A[i] <= R) {
                res.push_back(B[j]);
            }
        }
    }
    return res;
}