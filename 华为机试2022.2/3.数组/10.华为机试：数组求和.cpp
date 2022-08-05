/**
 * @file 10.华为机试：数组求和.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 100分】数组求和 [ 100 / 简单 ]

数组求和
题目描述：
给定一个数组，编写一个函数来计算它的最大N个数与最小N个数的和。你需要对数组进行去重。

说明:
数组中数字范围[0, 1000]
最大N个数与最小N个数不能有重叠，如有重叠，输入非法返回-1
输入非法返回-1
输入描述：
第一行输入M， M标识数组大小
第二行输入M个数，标识数组内容
第三行输入N，N表达需要计算的最大、最小N个数
输出描述：
输出最大N个数与最小N个数的和。

示例 1：

输入
5
95 88 83 64 100
2
1
2
3
输出
342
1
说明
最大2个数[100,95],最小2个数[83,64], 输出为342

示例 2：

输入
5
3 2 3 4 2
2
1
2
3
输出
-1
1
说明
最大2个数[4,3],最小2个数[3,2], 有重叠输出为-1
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123976557
 */
#include <vector>
#include <iostream>
#include <set>
using namespace std;
int minAndMaxSum(vector<int>& nums, int N) {
    set<int> s;
    for (int num : nums) {
        s.insert(num);
    }
    if (s.size() < N + N) {
        return -1;
    }
    set<int>::iterator it = s.begin();
    int sum = 0;
    // 最小的 N 个数
    for (int i = 0; i < N; ++i) {
        sum += (*it);
        it++;
    }
    // 跳过中间的 size - 2 * N 个数
    int rest = s.size() - 2 * N;
    for (int i = 0; i < rest; ++i) {
        it++;
    }
    // 最大的N个数
    for (; it != s.end(); ++it) {
        sum += *it;
    }
    return sum;

}

int main(int argc, char* argv[]) {
    int n = 0;
    int N = 0;
    while (1) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cin >> N;
        cout << minAndMaxSum(nums, N) << endl;
    }
    return 0;
} 