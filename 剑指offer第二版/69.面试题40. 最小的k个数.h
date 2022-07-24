/**
 * @file 69.面试题40. 最小的k个数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
 * 
 */
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:

    // cmp函数的定义需要两个参数，参数a和参数b，当满足一定的条件的时候返回ture或false，只需要记住一条规则:
    // 当返回值为true时，第一个参数放在前面，第二个参数放在后面；
    // 当放回为false时，第二个参数放在前面，第一个参数放在后面；
    class cmp {
    public:
        bool operator()(int x, int y) { return x < y; } 
    };

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, cmp> bigRootHeap;
        vector<int> res;
        if (arr.empty() || k == 0) return res;
        for (auto num : arr) {
            if (bigRootHeap.size() == k && num < bigRootHeap.top()) {
                bigRootHeap.pop();
                
            }
            if (bigRootHeap.size() < k) {
                bigRootHeap.push(num);
            }
        }

        while (!bigRootHeap.empty()) {
            res.push_back(bigRootHeap.top());
            bigRootHeap.pop();
        }
        return res;
    }
};