/**
 * @file 12.矩阵中的路径.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。



来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (process(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
        
    }
    //在 m n位置中寻找 word[i]
    bool process(vector<vector<char>>& board, string& word, int i, int m, int n) {
        if (i == word.size()) {
            return true;
        }
        if (m >= row || m < 0 || n >= col || n < 0 || board[m][n] != word[i]) {
            return false;
        }
        // 往四个方向搜索
        // 当前字符已经用过 修改为'/0'
        char c = board[m][n];
        board[m][n] = '\0';
        bool res = process(board, word, i + 1, m + 1, n) 
                || process(board, word, i + 1, m - 1, n)
                || process(board, word, i + 1, m, n + 1)
                || process(board, word, i + 1, m, n - 1);
        board[m][n] = c;
        return res;
    }

private:
    int row, col;
};