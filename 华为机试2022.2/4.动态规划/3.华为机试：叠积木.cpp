/**
 * @file 3.华为机试：叠积木.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 编程题目 | 100分】叠积木 [ 100 / 中等 ]

叠积木
题目描述
给出一个列表如[[6,7,],[5,4],[3,2]],表示木块的长和宽，当木块的长和宽不大于另个木块的长和宽时，就可以放在上面，此外数组还可以左右翻转。求最多能搭多少层。

输入描述
一个二维数组，里面是每个积木的长和宽，可以左右翻转。

输出描述
最多能搭多少层。

样例
输入
[[5,4],[6,3],[6,7],[6,6],[4,6]]
1
输出
4
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124261937
 */

/**
 * @brief 统一让大的数值作为长度 小的数值作为宽度 将问题转化为求最长递增子序列问题
 * 
 */

#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

struct block {
    int height = 0; // 长度
    int width = 0; // 宽度
    block() {

    }
    block(string str) {
        str.pop_back();
        int pos = str.find(',');
        height = atoi(str.substr(1, pos - 1).c_str());
        width = atoi(str.substr(pos + 1).c_str());
    }
};

bool cmp(block a, block b) {
    return a.height > b.height;
}

int maxLenOfOrderSubStr(vector<block>& blocks) {
    // 按照长度从大到小排序
    sort(blocks.begin(), blocks.end(), cmp);
    int size = blocks.size();
    vector<int> dp(size);
    dp[0] = 1;
    int res = 0;
    for (int i = 1; i < size; ++i) {
        dp[i] = blocks[i].width >= blocks[i - 1].width ? dp[i - 1] + 1 : 1;
        res = max(res, dp[i]);
    }
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        inputStr.pop_back();
        char* tmp = strtok((char*)(&inputStr[1]), ",");
        vector<block> blocks;
        while (tmp != NULL) {
            blocks.push_back(block(tmp));
            tmp = strtok(NULL, ",");
        }
        cout << maxLenOfOrderSubStr(blocks) << endl;
    }
    return 0;
}