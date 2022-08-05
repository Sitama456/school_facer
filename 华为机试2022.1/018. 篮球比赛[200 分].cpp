/**
 * @file 018. 篮球比赛[200 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125133206
 * 之后看到题目第一时间应该想暴力解法
 */
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief 枚举A队伍所有的组合
 * 
 * @param abilities 
 * @param i 
 * @param sumA 
 */
void process(vector<int>& abilities, int i, int sum,  vector<int>& sumArr, vector<bool>& used) {
    if (i == 5) {
        sumArr.push_back(sum);
        return;
    }
    // 要第几个球员
    for (int j = 0; j < abilities.size(); ++j) {
        if (used[j]) {
            continue;
        }
        used[j] = true;
        sum += abilities[j];
        process(abilities, i + 1, sum, sumArr, used);
        sum -= abilities[j];
        used[j] = false;
    }

}


int minimumAbility(vector<int>& abilities) {
    
}