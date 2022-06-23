/**
 * @file 3.预处理.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一些排成一行的正方形。每个正方形已被染成红色或者黑色。牛牛可以
 * 选择任意一个正方形然后用这两种颜色的任意一种进行染色,这个正方形的颜色会被
 * 覆盖。目标是完成染色后，每个红色R都比绿色G距离最左侧近。最少需要染几个正方形。
 * 例如 s = RGRGR
 * 染成 RRRGG就满足要求了，染色个数为2 即左侧全是R右侧全是G
 * 
 */

#include <string>
#include <vector>
using namespace std;

int minPaintTest(string& s) {
    int N = s.size();
    // 左 R 右 G
    int size = 0;
    for (int L = 0; L <= N; ++L) {
        if (L == 0) {
            // 统计 s[0 .. N - 1] 一共右多少R 全部染成 G
        } else if (L == N) {
            // 统计 s[0 .. N - 1] 一共有多少G 全部染成 R
        }
        else {
            // 统计 0 ~ L 有多少G 全部染成 R
            // 加上 L + 1 .. N - 1 一共有多少R 全部染成G
        }

    }

}

/**
 * @brief 优化 前缀数组
 * 
 */

/**
 * @brief 给定一个N * N 的矩阵，只有0和1 两种值，返回边框全是1的最大正方形
 * 的边长长度
 * 
 */

int maxAllOneBorder(vector<vector<int>> m) {
    int N = m.size();
    int M = m[0].size();

    //枚举所有的正方形(row col 为左上角点)
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < M; ++col) {
            // 枚举边长
            for (int border = 1; border <= min(N - row, M - col); ++border) {
                // 验证这正方形的四条边是否是1
                // for
                // for
                // for
                // for

            }
        }
    }
}
/**
 * @brief 可以预处理，用两个同样大小的矩阵 help1 help2。help1[i][j]表示包含自己在内右方有多少连续的1
 * help2[i][j]表示包含自己在内下方有多少连续的1
 * 
 */