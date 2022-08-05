/**
 * @file 1.华为机试：高效的任务规划.cpp
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
 * 【编程题目 | 200分】高效的任务规划 [ 200 / 中等 ]

高效的任务规划
题目描述：
你有 n 台机器编号为 1~n，每台都需要完成完成一项工作，机器经过配置后都能完成独立完成一项工作。
假设第 i 台机器你需要花 B 分钟进行设置，然后开始运行，J 分钟后完成任务。
现在，你需要选择布置工作的顺序，使得用最短的时间完成所有工作。
注意，不能同时对两台机器进行配置，但配置完成的机器们可以同时执行它们各自的工作。
注：此题对效率有要求，请考虑高效的实现方式

输入描述：
第一行输入代表总共有 M 组任务数据（1<M<=10）。
每组数第一行为一个整数，指定机器的数量 N（0<N<=1000）。
随后的 N 行每行两个整数，第一个表示 B（0<=B<=10000），第二个表示 J（0<=J<=10000）。
每组数据连续输入，不会用空行分隔。
各组任务单独计时。
输出描述：
对于每组任务，输出最短完成时间，且每组的结果独占一行。
例如，两组任务就应该有两行输出。
示例 1：

输入
1
1
2 2
1
2
3
输出
4
1
说明
第一行1为一组任务，
第二行1代表只有一台机器，
第三行表示该机器配置需2分钟，执行需要2分钟。
示例 1：

输入
2
2
1 1
2 2
3
1 1
2 2
3 3
1
2
3
4
5
6
7
8
输出
4
7
1
2
说明
第一行2代表两组任务，
第二行2代表第一组任务有2个机器，
第三行1 1代表机器1配置需要1分运行需要1分，
第四行2 2代表机器2配置需要2分运行需要2分，
第五行3代表第二组任务需要3个机器，
第6-8行分别表示3个机器的配置与运行时间。
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123996124
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct machine {
    int setTime = 0;
    int runTime = 0;
};

bool cmp(machine a, machine b) {
    return a.runTime > b.runTime;
}

int minTime(vector<machine>& machines) {
    int count = machines.size();
    vector<int> dp(count);
    // 让运行时间长的机器先配置
    sort(machines.begin(), machines.end(), cmp);
    // 第 i 台机器的时间 = 0 ~ i - 1的配置时间 + i 台机器的配置时间 + 运行时间
    int last = 0;
    int minTime = INT32_MIN;
    for (int i = 0; i < count; ++i) {
        dp[i] = last + machines[i].setTime + machines[i].runTime;
        last += machines[i].setTime;
        minTime = max(minTime, dp[i]);
    }
    return minTime;

}

int main(int argc, char* argv[]) {
    int taskCount = 0;
    while (1) {
        cin >> taskCount;
        for (int i = 0; i < taskCount; ++i) {
            int machineCount = 0;
            cin >> machineCount;
            vector<machine> machines(machineCount);
            for (int j = 0; j < machineCount; ++j) {
                cin >> machines[j].setTime;
                cin >> machines[j].runTime;
            }
            cout << minTime(machines) << endl;
        }
    }
    return 0;
}