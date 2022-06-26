/**
 * @file 04.二维数组中的查找.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        // 查找上限的行 最后一个小于等于num的数
        int up = 0, down = m;
        int row = -1;
        while (up < down) {
            int mid = up + (down - up) / 2;
            if (matrix[mid][0] <= target) {
                up = mid + 1;
                row = mid;
            } else {
                down = mid;
            }
        }
        if (row == -1) {
            return false;
        }
        // 查看在哪一列
        for (int i = 0; i <= row; ++i) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        
        return false;

    }
};