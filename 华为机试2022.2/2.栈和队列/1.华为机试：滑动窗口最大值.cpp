/**
 * @file 1.华为机试：滑动窗口最大值.cpp
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
 * 【编程题目 | 100分】滑动窗口最大值 [ 2022 Q1 考试题 ]

本题可使用本地IDE编码，不能使用本地已有代码。无跳出限制，编码后请点击"保存并提交"按钮进行代码提交。

题目描述：
有一个N个整数的数组，和一个长度为M的窗口，窗口从数组内的第一个数开始滑动直到窗口不能滑动为止， 每次窗口滑动产生一个窗口和（窗口内所有数的和），求窗口滑动产生的所有窗口和的最大值。

输入描述：
第一行输入一个正整数N，表示整数个数。（0<N<100000）
第二行输入N个整数，整数的取值范围为[-100,100]。
第三行输入一个正整数M，M代表窗口的大小，M<=100000，且M<=N。
输出描述：
窗口滑动产生所有窗口和的最大值。
示例 1 输入输出示例仅供调试，后台判题数据一般不包含示例

输入
6
12 10 20 30 15 23
3
1
2
3
输出
68
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123901424
 */

#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int maxWindowSum(vector<int>& nums, int k) {
    int size = nums.size();
    int left = 0;
    int right = 0;
    int maxSum = 0;
    int sum = 0;
    while (right < size) {
        // 右侧进来一个值
        sum += nums[right];
        // 左侧要出去一个值
        if (right - k >= 0) {
            sum -= nums[right - k];
        }
        if (right >= k - 1) {
            maxSum = max(sum, maxSum);
        }
        ++right;
    }
    return maxSum;

}

int main(int argc, char* argv[]) {
    int n = 0;
    int k = 0;
    while (1) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cin >> k;
        cout << maxWindowSum(nums, k) << endl;
    }
    return 0;
}