/**
 * @file 021. 素数之积[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125133828
 * 
 */

#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

/**
 * @brief 求质数因子
 * 
 * @param num 
 * @return vector<int> 
 */
vector<int> getPrimes(int num) {
    int tmp = num;
    vector<int> res;
    int limit = sqrt(num);
    for (int i = 2; i <= limit; ++i) {
        while (num % i == 0) {
            res.push_back(i);
            num /= i;
        }
    }
    // 如果剩余一个比2大的质数
    if (num != tmp && num > 2) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int num;
    while (1) {
        cin >> num;
        vector<int> primes = getPrimes(num);
        if (primes.size() != 2) {
            cout << -1 << " " << -1 << endl;
        } else {
            if (primes[0] * primes[1] == num) {
                cout << primes[0] << primes[1] << endl;
            } else {
                cout << -1 << " " << -1 << endl;
            }
        }
    }
}