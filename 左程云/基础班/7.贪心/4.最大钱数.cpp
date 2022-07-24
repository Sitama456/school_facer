/**
 * @file 4.最大钱数.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入:
 * 正数数组costs: costs[i]表示i号项目的花费
 * 正数数组profits: profits[i]表示i号项目在扣除花费之后还能挣到的钱(利润)
 * k:表示你只能串行的最多做k个项目
 * m: 表示你的初始资金
 * 说明：你每做完一个项目，马上获得的收益，可以支持你去做下一个项目。
 * 输出：
 * 你最后获得的最大钱数
 * 
 * 1) 先按花费组织成小根堆，成为锁定项目
 * 2) 根据初始资金解锁项目(从小根堆弹出), 放入到按收益组织的大根堆
 * 3) 从大根堆弹出一个项目去做
 */
#include <vector>
#include <queue>
using namespace std;
struct Program
{
    int cost;
    int profit;
    Program(int cost, int profit) : cost(cost), profit(profit) {}
};

int findMaximizedCapital(int k, int w, vector<int>& costs, vector<int>& profits) {
    priority_queue<Program, vector<Program>> lock_pq;
    bool cmp = [](Program x, Program y)->bool{ return x.profit > y.profit; };
    priority_queue<Program, vector<Program>, decltype(cmp)> unlock_pq;
    for (int i = 0; i < costs.size(); ++i) {
        lock_pq.push({costs[i], profits[i]});
    }
    for (int i = 0; i < k; ++i) {
        // 解锁项目
        while (!lock_pq.empty() && lock_pq.top().cost <= w) {
            unlock_pq.push(lock_pq.top());
            lock_pq.pop();
        }
        if (unlock_pq.empty()) {
            return w;
        }
        w += unlock_pq.top().profit;
    
        unlock_pq.pop();
    }
    return w;

}
