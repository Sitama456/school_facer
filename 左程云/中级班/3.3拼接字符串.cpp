/**
 * @file 3.3拼接字符串.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 假设 s 和 m 初始化，s = "a"; m = s;
 * 定义两种操作，第一种操作:
 * m = s;
 * s = s + s;
 * 
 * 第二种操作
 * s = s + m;
 * 
 * 求最小的操作步骤数，可以将s拼接到长度等于 n 
 * 
 * 1) 如果 n 是一个质数，则只调操作2的操作数最好
 *      假设 s = ka,调了操作1后，则  m = ka, s = 2ka。
 *      因为总会包含因子k 所以 k == 1, 所以只能第一步调操作1，但此时操作1和操作2的效果又是一样的
 * 2) 如果 n 不是质数，则假设 n 有某些质数因子构成的 n = a * b * c * d, 并假设以a b c d的顺序拼的操作数最少
 *      则最后一个 d 份(a * b * c) 份，调 d - 1 次操作2
 *       a * b * c 则需要 c 份 (a * b)
 *      所以需要调所有质数因子和减去质数因子个数 的操作2
 * 
 */

#include <vector>
using namespace std;

/**
 * @brief 请确保 n 不是质数
 * 
 * @param n 
 * @return vector<int> 所有质数的和 但是因子不包括 1  所有质数因子的个数 不包括1 
 */
vector<int> divsSumAndCount(int n) {
    int sum = 0;
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            sum += i;
            count++;
            n /= i;
        }
    }
    return {sum, count};
}

#include <math.h>
/**
 * @brief 判断一个数是否是质数
 * 
 * @param n 
 * @return true 
 * @return false 
 */
bool isPrim(int n) {
    if (n < 2) {
        return false;
    }
    int max = (int)sqrt((double)n);
    for (int i = 2; i <= max; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int minOps(int n) {
    if (n < 2) {
        return 0;
    }
    if (isPrim(n)) {
        return n - 1;
    }
    vector<int> count = divsSumAndCount(n);
    return count[0] - count[1];
}
