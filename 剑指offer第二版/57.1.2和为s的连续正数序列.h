/**
 * @file 57.1.2和为s的连续正数序列.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 双指针
        int i = 1; 
        int j = 1;
        int sum = 1;
        vector<vector<int>> res;
        while (j < target) {
            if (i > j) break;
            if (sum == target) {
                res.push_back(getVector(i, j));
                sum -= i;
                i++;
            } else if (sum > target) {
                sum -= i;
                i++;
            } else {
                j++;
                sum += j;
            }
        }
        return res;
    }

    vector<int> getVector(int i, int j) {
        vector<int> res;
        for (int k = i; k <= j; ++k) {
            res.push_back(k);
        }
        return res;
    }
    
};