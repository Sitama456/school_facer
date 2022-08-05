/**
 * @file 7.华为机试：玩牌高手.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 100分】玩牌高手 [ 100 / 中等 ]

玩牌高手
题目描述：
给定一个长度为n的整型数组，表示一个选手在n轮内可选择的牌面分数。选手基于规则选牌，请计算所有轮结束后其可以获得的最高总分数。

选择规则如下：

在每轮里选手可以选择获取该轮牌面，则其总分数加上该轮牌面分数，为其新的总分数。
选手也可不选择本轮牌面直接跳到下一轮，此时将当前总分数还原为3轮前的总分数，若当前轮次小于等于3（即在第1、2、3轮选择跳过轮次），则总分数置为0。
选手的初始总分数为0，且必须依次参加每一轮。
输入描述
第一行为一个小写逗号分割的字符串，表示n轮的牌面分数，1<= n <=20。
分数值为整数，-100 <= 分数值 <= 100。
不考虑格式问题。
输出描述
所有轮结束后选手获得的最高总分数。

示例 1：
输入
1,-5,-6,4,3,6,-2
1
输出
11
1
说明
总共有7轮牌面。
第一轮选择该轮牌面，总分数为1。
第二轮不选择该轮牌面，总分数还原为0。
第三轮不选择该轮牌面，总分数还原为0。
第四轮选择该轮牌面，总分数为4。
第五轮选择该轮牌面，总分数为7。
第六轮选择该轮牌面，总分数为13。
第七轮如果不选择该轮牌面，则总分数还原到3轮1前分数，即第四轮的总分数4，如果选择该轮牌面，总分数为11，所以选择该轮牌面。
因此，最终的最高总分为11。
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124060810
 */

#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @brief 第 i 轮的分数
 * 
 * @param nums 
 * @param i 
 * @return int 
 */
int maxScores(vector<int>& nums, int i) {
    if (i < 0) {
        return 0;
    }
    // 选择该轮牌面
    int res = nums[i] + maxScores(nums, i - 1);
    // 不选择该轮牌面
    res = max(res, maxScores(nums, i - 3));
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        char* tmp = strtok((char *)(inputStr.data()), ",");
        vector<int> nums;
        while (tmp != NULL) {
            nums.push_back(atoi(tmp));
            tmp = strtok(NULL, ",");
        }
        cout << maxScores(nums, nums.size() - 1) << endl;
    }
    return 0;
}