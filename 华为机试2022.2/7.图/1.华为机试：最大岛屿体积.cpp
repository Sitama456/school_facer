/**
 * @file 1.华为机试：最大岛屿体积.cpp
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
 * 编程题目 | 100分】最大岛屿体积 [ 100 / 中等 ]

最大岛屿体积
题目描述
给你一个由 大于0的数（陆地）和 0（水）组成的的二维网格，请你计算网格中最大岛屿的体积。陆地的数表示所在岛屿的体积。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

输入描述
第一行是二维网格的宽和高。
后面几行是二维网格。

输出描述
输出岛屿的最大体积。

样例
输入
5 5
0 1 1 0 0
0 1 1 0 0
0 0 0 0 0
0 0 1 2 3
0 0 1 3 9
1
2
3
4
5
6
输出
19
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124249565
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int infect(vector<vector<int>>& island, int i, int j) {
    if (i >= island.size() || i < 0 || j >= island[0].size() || j < 0 || island[i][j] == 0) {
        return 0;
    }
    int res = island[i][j];
    island[i][j] = 0;
    res += infect(island, i, j - 1);
    res += infect(island, i - 1, j);
    res += infect(island, i, j + 1);
    res += infect(island, i + 1, j);
    return res;
}

int maxAreaOfIsland(vector<vector<int>>& island) {
    int m = island.size();
    int n = island[0].size();
    int maxArea = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            maxArea = max(maxArea, infect(island, i, j)); 
        }
    }
    return maxArea;
}

int main(int argc, char* argv[]) {
    int m = 0;
    int n = 0;
    while (1) {
        cin >> n;
        cin >> m;
        vector<vector<int>> island(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> island[i][j];
            }
        }
        cout << maxAreaOfIsland(island) << endl;
    }
    return 0;
}