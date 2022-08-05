/**
 * @file 2.华为机试：机智的外卖员.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 100分】机智的外卖员 [ 100 / 中等 ]

机智的外卖员
题目描述：
外卖员每天在大厦中送外卖，大厦共有L层（0<L<=10^5），当他处于第N层楼时，可以每分钟通过步行梯向上达到N+1层，或向下达到N-1层，或者乘坐电梯达到2*N层。给定他所处位置N，以及外卖配送的目的楼层M，计算他送达的最短时间。

输入描述
当前所处楼层N和外卖配送的目的楼层M

输出描述
送达的最短时间

样例
输入
5 17
1
输出
4
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124246788
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minTime(int N, int M) {
    if (N >= M) return N - M;

    vector<int> dp(M + 1); // 到达第i层的最短时间
    // 从当前层到以下的层 只能步行
    for (int i = 0; i <= N; ++i) {
        dp[i] = N - i;
    }
    // 从 N 到 M的层 
    for (int i = N + 1; i <= M; ++i) {
        // 如果是偶数层 则可以直接从 i / 2 坐电梯上来 也可以从 i - 1走上来
        if (i % 2 == 0) {
            dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
        } else {
            // 如果是奇数层 则可以从 i / 2 坐电梯上来在爬一层 也可以从i - 1走上来
            dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 2);
        }
    }

    return dp[M];

}

int main(int argc, char* argv[]) {
    int N = 0;
    int M = 0;
    while (1) {
        cin >> N;
        cin >> M;
        cout << minTime(N, M) << endl;
    }
    return 0;
}