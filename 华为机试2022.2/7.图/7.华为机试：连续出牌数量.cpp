/**
 * @file 7.华为机试：连续出牌数量.cpp
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
 * 【编程题目 |200分】连续出牌数量【2022 Q1,Q2考试题】

题目描述
手里给一副手牌，数字从0-9，有r(红色),，g(绿色），b(蓝色)，y(黄色)四种颜色，出牌规则为每次打出的牌必须跟上一张的数字或者颜色相同，否则不能抽选。
选手应该怎么选才能使得抽选的次数最大，并且输出这个最大次数。
输入描述
第一行 牌的数值n (1<=n<=9)
第二行 牌的颜色（r,g,b,y四种颜色表示)
输出描述
输出最大出牌数量
示例
输入
1 4 3 4 5
r y b b r
1
2
输出
3
1
说明
如果打（1, r）-> (5, r)，那么能打两张。

如果打（4，y) -> (4, b) -> (3, b)，那么能打三张。

思路分析
这道题还可以考虑BFS，相同数字或者相同颜色的都存入连续关系。

从第一个进如队列，统计每一个对应的最大次数，最后再更新最大值。

存入连续关系得时候可以使用二维list

以序号为索引，判断元素相同或颜色相同的都加入相应的list。

然后就是常规的BFS入队进行处理。
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/125824964
 */

#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

struct card {
    int num = 0;
    char color;
};

/**
 * @brief 出第 i 张牌的最大出牌数
 * 
 * @param cards 
 * @param i 
 * @param used 
 * @return int 
 */
int dfs(vector<card>& cards, int i, vector<bool>& used) {
    if (i == cards.size()) return 0;
    int res = 1;

    // 下一张尝试出牌
    for (int j = 0; j < cards.size(); ++j) {
        if (used[j] == true) continue;
        // 必须数字一样或者颜色一样才能出牌
        if (cards[i].color == cards[j].color || cards[i].num == cards[j].num) {
            used[j] = true;
            res = max(res, 1 + dfs(cards, j, used));
            used[j] = false;
        }
    }
    return res;
}

int maxSendedCardCount(vector<card>& cards) {
    int size = cards.size();
    vector<bool> used(size, false);
    int maxCount = 0;
    // 选则打第 i 张牌
    for (int i = 0; i < size; ++i) {
        used[i] = true;
        maxCount = max(maxCount, dfs(cards, i, used));
        used[i] = false;
    }
    return maxCount;

}




int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        getline(cin, inputStr);
        char* tmp = strtok((char*)(inputStr.data()), " ");
        vector<int> nums;
        while (tmp != NULL) {
            nums.push_back(atoi(tmp));
            tmp = strtok(NULL, " ");
        }
        getline(cin, inputStr);
        tmp = strtok((char*)(inputStr.data()), " ");
        vector<char> colors;
        while (tmp != NULL) {
            colors.push_back(tmp[0]);
            tmp = strtok(NULL, " ");
        }
        int size = nums.size();
        vector<card> cards(size);
        for (int i = 0; i < size; ++i) {
            cards[i].num = nums[i];
            cards[i].color = colors[i];
        }
        cout << maxSendedCardCount(cards) << endl;
    }
    return 0;
}