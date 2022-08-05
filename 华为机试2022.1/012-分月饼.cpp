/**
 * @file 012-分月饼.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125117439
 * 
 */
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @brief m 个人分 rest个月饼，min 是前一个少的月饼个数
 * 
 * @param m 
 * @param pre 
 * @param rest 
 * @return int 
 */
int distribute(int m, int rest, int min) {
    if (m <= 0) return 0;
    if (rest <= 0) return 0;
    if (m == 1) {
        if (rest >= min && rest <= min + 3) {
            return 1;
        }
        return 0;
    }
    int methods = 0;
    // 注意 这里是一直在min上加的
    for (int i = min; i <= min + 3; i++) {
        methods += distribute(m - 1, rest - i, i);
    }
    return methods;
}

int main() {
    while (1) {
        int m = 0;
        int n = 0;
        cin >> m;
        cin >> n;
        if (m > n) cout << 0 << endl;;
        int rest = n - m;
        int count = 0;
        for (int i = 0; i < rest; ++i) {
            // 确定最少的那个人的月饼
            // 第二少的只能是 [i, i + 3]个
            count += distribute(m - 1, rest - i, i);
        }
        cout << count << endl;
    }
    

}
