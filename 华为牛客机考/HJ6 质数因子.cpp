/**
 * @file HJ6 质数因子.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）


数据范围： 1 \le n \le 2 \times 10^{9} + 14 \1≤n≤2×10 
9
 +14 
输入描述：
输入一个整数

输出描述：
按照从小到大的顺序输出它的所有质数的因子，以空格隔开。
 */

#include<iostream>
#include <math.h>
#include <vector>
using namespace std;



vector<int> getMultFactor(int n) {
    vector<int> res;
    int limit = sqrt(n);
    if (n < 2) {
        return res;
    }
    for (int i = 2; i <= limit; ++i) {
        // 能被 i 整除
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    // 如果一个正整数能被不大于sqrt(n)的数分解 则最后的n只有三种结果
    // 1 或者 2: 被分解了 比如 8 = 2 * 2 * 2 * 1
    // 大于2 : 表示剩余一个大质数  比如 14 = 2 * 7  6 = 2 * 3 
    if (n > 2) {
        res.push_back(n);
    }
    return res;
}

int main(){
    int num = 0;
    cin >> num;
    vector<int> res = getMultFactor(num);
    if (res.empty()) {
        res.push_back(num);
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}