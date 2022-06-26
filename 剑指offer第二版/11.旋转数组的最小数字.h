/**
 * @file 11.旋转数组的最小数字.h
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
 * 
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为 1。  

注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        if (n == 1) return numbers[0];
        int res = numbers[0];
        for (int i = 0; i < n - 1; ++i) {
            if (numbers[i + 1] < numbers[i]) {
                res = min(res, numbers[i + 1]);
            }
        }
        return res;
    }
};
