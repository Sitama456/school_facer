/**
 * @file 13.机器人的运动范围.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int movingCount(int m, int n, int k) {
        used.resize(m, vector<bool>(n, false));
        return procecc(m, n, 0, 0, k);
    }

    // 从 i j 位置最多可以到达多少格子
    int procecc(int m, int n, int i, int j, int k) {
        if (i >= m || j >= n || i < 0 || j < 0 || getSum(i, j) > k) {
            return 0;
        }
        if (used[i][j]) {
            return 0;
        }
        used[i][j] = true;
        int left = procecc(m, n, i, j - 1, k);
        int up = procecc(m, n, i - 1, j, k);
        int right = procecc(m, n, i, j + 1, k);
        int down = procecc(m, n, i + 1, j, k);
        // 注意 这里不应该再设为 false了 因为是求格子数目 而不是路径
        // colUsed[j] = false;
        // rowUsed[i] = false;
        int res = 1 + left + up + right + down;
        return res;


    }

    int getSum(int i, int j) {
        int sum = 0;
        while (i) {
            sum += i % 10;
            i /= 10;
        }
        while (j) {
            sum += j % 10;
            j /= 10;
        }
        return sum;
    } 

private:
    vector<vector<bool>> used;
};