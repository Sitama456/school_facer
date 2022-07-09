/**
 * @file 47.礼物的最大价值.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        // vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        // for (int i = row - 1; i >= 0; --i) {
        //     for (int j = col - 1; j >= 0; --j) {
        //         dp[i][j] = grid[i][j] + max(dp[i][j + 1], dp[i + 1][j]);
        //     }
        // }
        // return dp[0][0];
        vector<int> dp(col + 1, 0);
        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                dp[j] = grid[i][j] + max(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }

    // 从(i, j)出发 拿到的最大礼物价值
    int process(vector<vector<int>>& grid, int i, int j) {
        // 越界了 拿不到礼物
        if (i == grid.size() || j == grid[0].size()) {
            return 0;
        }
        // 向右走
        int rightValue = grid[i][j] + process(grid, i, j + 1);
        // 向下走
        int downValue = grid[i][j] + process(grid, i + 1, j);
        return max(rightValue, downValue);
    }
};