/**
 * @file 1.随机数组生成.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <time.h>
#include <random>

using namespace std;

/**
 * @brief 生成长度为 1 ~ N 大小为 min ~ max的随机数组
 * 
 * @param N 
 * @param min 
 * @param max 
 * @return vector<int> 
 */
vector<int> randomArrayGenerator(int N, int min, int max) {
    time(NULL);
    int len = rand() % (N + 1);
    vector<int> arr(len, 0);
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % (max - min + 1) + min;
    }
    return arr;
}