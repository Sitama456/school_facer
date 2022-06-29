/**
 * @file 4.7咖啡杯went.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个数组，元素全是正数。每一个数代表一台咖啡机泡咖啡所需要
 * 的时间。每台机器只能冲一杯咖啡。给定一个数N,代表有多少人要喝咖啡，每人
 * 只喝一杯。N个人之间存在排队的问题，认为喝咖啡的时间为0。给定一个参数a,
 * 表示只有一台洗咖啡的机器洗咖啡的时间，一次只能洗一杯咖啡。给定一个参数b，
 * 表示不洗也能自然挥发的时间。
 * 问从所有人都喝完一杯并且杯子变干净所需的最少时间。参数:
 * arr[...]:
 * N:
 * a:
 * b:
 * 
 */

/**
 * @brief 
 * 1) 先只统计N个人拿到咖啡的时间，将咖啡机的效率和时间组织成小根堆(0 2)表示
 * 0时刻效率为2这台咖啡机可用。这个数组也是每个人需要洗的时间
 * 2) 面对所有人喝完的数组，如何洗得快
 * 
 */

#include <vector>
#include <queue>
using namespace std;

struct Machine {
    int timePoint;
    int workTime;
    Machine(int t, int w) : timePoint(t), workTime(w) { }
};

/**
 * @brief 假设洗咖啡得机器，在washLine的时间才有空
 * 
 * @param drinks 洗咖啡数组
 * @param a 咖啡机洗一杯的时间
 * @param b 自然挥发的时间
 * @param index 当前的杯子
 * @param washLine 机器空闲时间点
 * @return int 如果要洗完drinks[index...N-1], 返回最早完成所有事情的时间点
 */
int process(vector<int>& drinks, int a, int b, int index, int washLine) {
    // 最后一杯了
    if (index == drinks.size() - 1) {
        // 咖啡机空闲的时间 和 我喝完的时间 中的最大值 才能选择用机器洗
        // 第二种自然挥发方式
        return min(max(washLine, drinks[index]) + a, drinks[index] + b);
    }
    // 当前咖啡杯决定放到咖啡机中洗，洗完的时间点
    int wash = max(washLine, drinks[index]) + a;
    // 洗完剩下所有的咖啡杯最早的结束时间
    int next1 = process(drinks, a, b, index + 1, wash);

    // 自己洗完 和 剩下的杯子洗完的时间 中的最大的时间点就是瓶颈
    int p1 = max(wash, next1);

    // 自然挥发的可能性
    int dry = drinks[index] + b;
    int next2 = process(drinks, a, b, index + 1, washLine);
    int p2 = max(dry, next2);

    return min(p1, p2);
}

//todo  改动态规划

int minTime(vector<int>& arr, int N, int a, int b) {
    bool cmp = [](Machine x, Machine y)->bool
        {return (x.timePoint + x.workTime) < (y.timePoint + y.workTime);};
    priority_queue<Machine, vector<Machine>, decltype(cmp)> heap;
    for (int i = 0; i < arr.size(); ++i) {
        heap.push({0, arr[i]});
    }
    vector<int> drink(N);
    for (int i = 0; i < N; ++i) {
        // 选择最早能拿到咖啡的机器 
        Machine cur = heap.top();
        heap.pop();
        // 更新cur机器的可用的时间点
        cur.timePoint += cur.workTime;
        // 拿到咖啡的时间点
        drink[i] = cur.timePoint;
        heap.push(cur);
    }
    return process(drink, a, b, 0, 0);
}