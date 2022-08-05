/**
 * @file 3.华为机试：污染水域.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 200分】污染水域 [ 200 / 中等 ]

题目描述
输入一行字符串，字符串可转换为N*N的数组，数组可认为是一个水域，判断多少天后，水域被全部污染。
数组中只有0和1，0表示纯净，1表示污染，每天只可污染上下左右的水域，如果开始全部被污染，或永远无法污染，则返回-1。

示例
输入
1,0,1,0,0,0,1,0,1
1
输出
2
1
解释：

转化为数组为：

1 0 1
0 0 0
1 0 1
1
2
3
4
5
第一天后水域变为

1 1 1
1 0 1
1 1 1
1
2
3
4
5
第二天全部被污染
1
输入
0,0,0,0
1
输出
-1
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/125793750

多源BFS https://blog.csdn.net/weixin_44052055/article/details/124838754
 */

#include <string.h>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <iostream>

using namespace std;



/**
 * @brief 多源bfs
 * 
 * @param lakes 
 * @return int 
 */
int minInfecDays(vector<vector<int>>& lakes) {
    int m = lakes.size();
    int n = lakes[0].size();
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    
    // 多个污染源入队
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (lakes[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    // 如果没有污染源或全是污染源
    if (q.empty() || q.size() == m * n) return -1;

    pair<int, int> pos;
    while (!q.empty()) {
        pos = q.front();
        q.pop();
        // 污染新的水域
        int i = pos.first;
        int j = pos.second;
        for (int k = 0; k < 4; ++k) {
            int newI = i + dx[k];
            int newJ = j + dy[k];
            // 如果越界或者已经是污染水域了 就跳过
            if (newI < 0 || newI >= m || newJ < 0 || newJ >= n || lakes[newI][newJ] != 0) {
                continue;
            }
            // 污染该水域 可以修改数组值为污染源 + 1 这样就可以用最后的污染水域的值 - 1 作为返回值
            lakes[newI][newJ] = lakes[i][j] + 1;
            q.push({newI, newJ});
        }
    }

    return lakes[pos.first][pos.second] - 1;
}

int main() {
    string inputStr;
    while (1) {
        cin >> inputStr;
        int N = 0;
        vector<int> tmpV;
        char* tmp = strtok((char *)(inputStr.data()), ",");
        while (tmp != NULL) {
            N++;
            tmpV.push_back(atoi(tmp));
            tmp = strtok(NULL, ",");
        }
        int m = sqrt(N);
        vector<vector<int>> lakes(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                lakes[i][j] = tmpV[i * m + j];
            }
        }
        cout << minInfecDays(lakes) << endl;
    }
    return 0;
}