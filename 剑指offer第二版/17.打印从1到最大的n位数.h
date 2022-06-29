/**
 * @file 17.打印从1到最大的n位数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
 * 
 */
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<int> printNumbers(int n) {
        long num = pow(10, n);
        vector<int> res(num - 1);
        for (int i = 1; i < num; ++i) {
            res[i - 1] = i;
        }
        return res;
    }
};