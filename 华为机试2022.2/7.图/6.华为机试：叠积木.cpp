/**
 * @file 6.华为机试：叠积木.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 200分】叠积木 [ 200 / 中等 ]

题目描述
有一堆长方体积木，它们的长度和宽度都相同，但长度不一。

小橙想把这堆积木叠成一面墙，墙的每层可以放一个积木，也可以将拼接多个积木，要求每层的长度相同。最少2层。

若必须用完这些积木，叠成的墙最多为多少层？

输入描述
输入为一行，为各个积木的长度，数字为正整数，并由空格分隔。积木的数量和长度都不超过5000。

输出描述
输出一个数字，为墙的最大层数，如果无法按要求叠成每层长度一致的墙，则输出-1。

示例
输入
3 6 3 3 3
1
输出
3
1
解释：以 6 为底的墙，第一层为 6 ，第二层为 3 + 3，第三层 3 + 3。

输入
9 9 9 5 3 2 2 2 2 2
1
输出
5
1
解释：

5+2+2=9

3+2+2+2=9

9,9,9

共五层
1
2
3
4
5
6
7
输入
3 5
1
输出
-1
1
思路分析
这道题要求每层的长度一样，且每层可以由多个积木拼接起来。

这道题目考察了回溯法，可以参考leetcode:698. 划分为k个相等的子集。

划分k个相同子集，就是保证每个子集都相同，总共划分k个。k就相当于我们的积木层数，子集就相当于我们一层积木的长度。

因此我们只需要遍历层数，判断是否可以拼成，从第2层遍历到sum/2，对遍历的每一层，首先判断是否可以分配sum % i == 0
，如果可以则回溯判断，同时更新最大层数。

所以这道题的核心就是是否可以划分k个相同子集。

先看一下leetcode的这道题目：这道题搞明白了，上面这道题自然也就解决了。
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/125790832
 */

/**
 * @brief 问题转化为 n 块积木 放到 k 个桶内 问 k 的最大值是多少
 * 
 */
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @brief 第 i 块积木放到哪个桶里 能否放进去
 * 
 * @param nums 
 * @param i 
 * @param bucket 
 * @param k 
 * @param target 
 * @return true 
 * @return false 
 */
bool backtrack(vector<int>& nums, int i, vector<int>& layer, int k, int target) {
    if (i == nums.size()) {
        // 证明所有的积木都正确放入层中了
        return true;
    }
    // 开始做选择 放入哪一层
    for (int j = 0; j < k; ++j) {
        // 对于第一块积木 放在哪都无所谓 所以直接让它放在第一层
        if (j > 0 && i == 0) break; // 剪枝优化
        // 可以加入这一层
        if (layer[j] + nums[i] <= target) { // 剪枝
            layer[j] += nums[i];
            if (backtrack(nums, i + 1, layer, k, target)) return true;
            // 回溯
            layer[j] -= nums[i];
        }

    }
    // 如果所有尝试都失败了 就失败了
    return false;
}

bool cmp (int a, int b) {
    return a > b;
}

int maxLayerCount(vector<int>& blocks) {
    int sum = 0;
    for (int block : blocks) {
        sum += block;
    }
    // 让大积木先选 可以提高剪枝的命中率
    sort(blocks.begin(), blocks.end(), cmp);
    int res = -1;
    for (int i = 2; i < sum; ++i) {
        if (sum % i != 0) continue;
        int target = sum / i;
        vector<int> layers(i, 0);
        // 可以被 i 层划分
        if (backtrack(blocks, 0, layers, i, target)) {
            res = max(res, i);
        }
    }
    return res;

}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        getline(cin, inputStr);
        char* tmp = strtok((char*)(inputStr.data()), " ");
        vector<int> blocks;
        while (tmp != nullptr) {
            blocks.push_back(atoi(tmp));
            tmp = strtok(NULL, " ");
        }
        cout << maxLayerCount(blocks) << endl;
    }
    return 0;
}