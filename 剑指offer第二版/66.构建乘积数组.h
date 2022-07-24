/**
 * @file 66.构建乘积数组.h
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
 * 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;
class Solution {
public:

    // 表格法
    // b0    1 a1 a2 a3 a4 ... an
    // b1   a0 1 a2 a3 a4 ... an
    // b2   a0 a1 1 a3 a4 ... an
    // ...........
    //bn-1  a0 a1 a2 a3 a4 ...1 an
    // bn   a0 a1 a2 a3 a5 ... 1
    vector<int> constructArr(vector<int>& a) {
        if (a.empty()) return {};
        int size = a.size();
        vector<int> b(size);
        b[0] = 1;
        // 下三角的乘积
        for (int i = 1; i < size; ++i) {
            b[i] = b[i - 1] * a[i - 1];
        }

        // 上三角的乘积
        int tmp = 1;
        for (int i = size - 1; i >= 0; --i) {
            b[i] *= tmp;
            tmp *= a[i];
        }
        return b;
    }
};