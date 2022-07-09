/**
 * @file 29.顺时针打印矩阵.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        if (matrix[0].empty()) return res;
        int tR = 0;
        int tC = 0;
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        
        while (tR <= dR && tC <= dC) {
            process(tR++, tC++, dR--, dC--, res, matrix);
        }
        return res;
    }

    void process(int arow, int acol, int brow, int bcol, vector<int>& res, vector<vector<int>>& matrix) {
        if (arow == brow) {
            for (int j = acol; j <= bcol; ++j) {
                res.push_back(matrix[arow][j]);
            }
            return;
        }
        if (acol == bcol) {
            for (int i = arow; i <= brow; ++i) {
                res.push_back(matrix[i][acol]);
            }
            return;
        }
        int i = arow, j = acol;
        for(; j < bcol; ++j) {
            res.push_back(matrix[i][j]);
        }
        for(; i < brow; ++i) {
            res.push_back(matrix[i][j]);
        }
        for(; j > acol; --j) {
            res.push_back(matrix[i][j]);
        }

        for(; i > arow; --i) {
            res.push_back(matrix[i][j]);
        }

    }
};