/**
 * @file 60.n个骰子的点数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

 

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        int sum = pow(6, n);
        vector<int> nums = process(n);
        vector<double> res(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = nums[i] * 1.0 / sum;
        } 
        return res;
    }
    // n 个骰子 第 i 个点数的组合个数
    vector<int> process(int n) {
        if (n == 1) {
            return { 1, 1, 1, 1, 1, 1 };
        }
        // 前一个骰子的组合数
        vector<int> pre = process(n - 1);
        vector<int> res(5 * n + 1);
        for (int i = 0; i < pre.size(); ++i) {
            // 当前骰子的点数 只可能是1 到 6 但排序是从 0 开始 所以是 0 ~ 5
            for (int j = 0; j < 6; ++j) {
                // 比如 res[0] 对应的是点数为2 第一个骰子点数为1 对其有贡献
                // res[1] 对应的点数为3，当前骰子为2 第一个骰子点数为1 也对其有贡献
                res[i + j] += pre[i];
            }
        }
        return res;

    }
};