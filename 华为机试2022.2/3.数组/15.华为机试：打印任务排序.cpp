/**
 * @file 15.华为机试：打印任务排序.cpp
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
 * 【编程题目 | 200分】打印任务排序 [ 200 / 中等 ]

题目描述
某个打印机根据打印队列执行打印任务。打印任务分为九个优先级，分别用数字1-9表示，数字越大优先级越高。打印机每次从队列头部取出第一个任务A，
然后检查队列余下任务中有没有比A优先级更高的任务，如果有比A优先级高的任务，则将任务A放到队列尾部，否则就执行任务A的打印。
请编写一个程序，根据输入的打印队列，输出实际的打印顺序。
输入描述
输入一行，为每个任务的优先级，优先级之间用逗号隔开，优先级取值范围是1~9。

输出描述
输出一行，为每个任务的打印顺序，打印顺序从0开始，用逗号隔开
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/125812220
 */

#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct task {
    int priority = 0;
    int id = 0;
    task() {}
    task(int p, int i) : priority(p), id(i) {}
};

struct cmp {
    bool operator()(task a, task b) {
        return a.priority < b.priority;
    }
};

string order(vector<task>& tasks) {
    priority_queue<task, vector<task>, cmp> bigRootHeap; // 大根堆
    for (task& t : tasks) {
        bigRootHeap.push(t);
    }
    string res;
    while (!bigRootHeap.empty()) {
        res += to_string(bigRootHeap.top().id);
        res += ",";
        bigRootHeap.pop();
    }
    res.pop_back();
    return res;
}

int main() {
    string inputStr;
    while (1) {
        cin >> inputStr;
        char *tmp = strtok((char *)(inputStr.data()), ",");
        vector<task> tasks;
        int id = 0;
        while (tmp != NULL) {
            tasks.push_back({atoi(tmp), id++});
            tmp = strtok(NULL, ",");
        }
        cout << order(tasks) << endl;
    }
    return 0;
}