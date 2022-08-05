/**
 * @file 042. 补种未成活胡杨[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125194456
 * 双指针
 */
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int mostTrees(int N, int K, vector<int>& dieTrees) {
    int size = dieTrees.size();
    int right = 0;
    int res = 0;
    while (right < size) {
        int maxBound = right == size - 1 ? N + 1 : dieTrees[right + 1];
        int minBound = 0;
        // 窗口为K 左边要舍弃一颗树
        if (right - K >= 0) {
            minBound = dieTrees[right - K];
        }
        // 此时为左开右开区间
        res = max(res, maxBound - minBound - 1);
        right++;
    }
    return res;
}

int main(int argc, char* argv[]) {
    int N = 0;
    int M = 0;
    int K = 0;
    while (1) {
        cin >> N;
        cin >> M;
        vector<int> dieTrees(M);
        int i = 0;
        while (i < M) {
            cin >> dieTrees[i++];
        }
        cin >> K;
        cout << mostTrees(N, K, dieTrees) << endl;
    }
    return 0;
} 