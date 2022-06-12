/**
 * @file 1.安排最多项目.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一些项目的开始时间和结束时间，都需要利用会议室。请问怎么安排使得会议最多
 * 贪心策略：谁先结束 谁先来
 * 
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/**
 * @brief 贪心算法在笔试时的解题套路
 * 1. 实现一个不依靠贪心策略的解法X，可以用最暴力的尝试 比如全排列 枚举
 * 2. 脑补出贪心策略A、 贪心策略B、贪心策略C...
 * 3.用解法X和对数器，去验证每一个贪心策略
 * 
 */





class Program {
public:
    int start;
    int end;
    Program(int s, int e) : start(s), end(e) {}


};

int bestArrange(vector<Program>& programs, int timePoint) {
    // 按结束时间排序
    bool cmp = [](Program a, Program b)->bool { return a.end < b.end;};
    sort(programs.begin(), programs.end(), cmp);
    int result = 0;
    for (int i = 0; i < programs.size(); ++i) {
        // 安排这个会议
        if (timePoint < programs[i].start) {
            result++;
            timePoint = programs[i].end;
        }
    }
    return result;
    
}

