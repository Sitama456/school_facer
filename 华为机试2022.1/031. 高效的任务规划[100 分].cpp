/**
 * @file 031. 高效的任务规划[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125157088
 * 让工作时间较长的机器先运行
 * 
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct machineTask {
    int configTime = 0;
    int taskTime = 0;
    machineTask(int config, int task) : configTime(config), taskTime(task) {}
};

bool cmp(machineTask a, machineTask b) {
    return a.taskTime > b.taskTime;
}

int minTime(vector<machineTask>& task) {
    int size = task.size();
    // 按照工作时长降序排序
    sort(task.begin(), task.end(), cmp);
    // 当前这台机器运行完成的时间
    vector<int> dp(size);
    int last = 0; // i 台机器之前的所有机器的配置时间
    int res = INT32_MIN;
    for (int i = 0; i < size; ++i) {
        // 一台机器运行所需要的时间 = 前面所有机器的配置时间 + 这台机器的配置时间 + 工作时间
        dp[i] = task[i].configTime + task[i].taskTime + last;
        last += task[i].configTime;
        res = max(res, dp[i]);
    }
    return res;

}

int main() {
    return 0;
}