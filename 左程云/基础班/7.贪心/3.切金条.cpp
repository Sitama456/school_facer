/**
 * @file 3.切金条.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 一块金条切成凉拌，是需要花费和长度值一样的铜板的。比如长度为20的金条，不管切成长度
 * 为多大的两半，都要花费20个铜板。
 * 一群人想整分整块金条，怎么分最省铜板
 * 例如，给定数组[10, 20, 30], 代表一共三个人，整块金条长度为10 + 20 + 30 = 60。金条要切成
 * 10 20 30的长度。如果先把长度60的金条分成10和50，花费60，再把50切位20和30， 花费50。总共
 * 需要110铜板；也可以先切为30 + 30，再把30切为10+20，花费90
 * 给定一个数组，返回最小代价
 * 经典哈夫曼编码问题:
 * 1. 把所有的数放入小根堆里。
 * 2. 一次弹出两个数 做结合，将结合的数字扔到小根队里。反复如此 
 */
#include <vector>
#include <queue>
using namespace std;

int lessMoney(vector<int>& arr) {
    priority_queue<int, vector<int>> pq;
    for (int i = 0; i < arr.size(); ++i) {
        pq.push(arr[i]);
    }
    int sum = 0;
    int cur1 = 0;
    int cur2 = 0;
    while (!pq.empty()) {
        cur1 = pq.top();
        pq.pop();
        cur2 = pq.top();
        pq.top();
        sum += (cur1 + cur2);
        pq.push(cur1 + cur2);
        
    }
    return sum;
}