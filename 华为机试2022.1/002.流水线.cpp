/**
 * @file 002.流水线.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125111393
 * 将流水线上的任务进行排序，时长最短的就是执行下一个任务的流水线，加上该任务 每次更新。
 */
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};


int minTime(vector<int>& jobs, int n) {
    int jobNum = jobs.size();
    sort(jobs.begin(), jobs.end());
    // 如果任务数没有流水线数量多 直接返回最大的
    if (jobNum <= n) {
        return jobs[jobNum - 1];
    }
    // 先执行第一批任务。
    // 流水线 小根堆
    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(jobs[i]);
    }
    // 执行后续任务时 选出当前执行任务时间最短的流水线去执行下一个任务
    for (int i = n; i < jobNum; ++i) {
        int curr = pq.top();
        pq.pop();
        pq.push(curr + jobs[i]);
    }
    // 此时 pq中就是每条流水线作业的时长 选最长的
    int res = 0;
    while (!pq.empty()) {
        res = max(res, pq.top());
        pq.pop();
    }
    return res;

}