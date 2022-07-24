/**
 * @file 剑指 Offer II 013. 二维子矩阵的和.
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一个二维矩阵 matrix，以下类型的多个请求：

计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。
实现 NumMatrix 类：

NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 返回左上角 (row1, col1) 、右下角 (row2, col2) 的子矩阵的元素总和。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/O4NDxx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
       if (matrix.empty() || matrix[0].empty()) return;
       int m = matrix.size();
       int n = matrix[0].size();
       preSumMat.resize(m + 1, vector<int>(n + 1, 0));
       for (int i = 0; i < m; ++i) {
           for (int j = 0; j < n; ++j) {
               preSumMat[i + 1][j + 1] = preSumMat[i + 1][j] + preSumMat[i][j + 1] - preSumMat[i][j] + matrix[i][j];
           }
       }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSumMat[row2 + 1][col2 + 1] - preSumMat[row2 + 1][col1] - preSumMat[row1][col2 + 1] + preSumMat[row1][col1];
    }

    vector<vector<int>> preSumMat;//二维数组前缀和 注意次数 sums[i, j] 表示 [0, 0] 到 [i - 1, j - 1]的所有元素和
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */