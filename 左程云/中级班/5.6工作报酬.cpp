/**
 * @file 5.6工作报酬.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选
 * 工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在
 * 牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作。牛牛依然使用
 * 自己的标准来帮助小伙伴们。
 * 
 * class Job {
 *    int money;
 *    int hard;
 * }
 * 给定一个job类型的数组jobarr,表示所有的工作。给定一个int类型的数组，表示
 * 所有小伙伴的能力。返回int类型的数组，表示每一个小伙伴按照牛牛的标准工作
 * 后所能获得的报酬。
 * 
 * 把所有的工作难度由小到大排序，难度相等的报酬从大到小。最后只留下组长。
 * 然后在组长中留下难度增加，报酬也增加的，其余的也删掉。
 * 
 */

class Job {
public:
    int money;
    int hard;
    Job(int m, int h) : money(m), hard(h) {}
};
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> getMoneys(vector<Job>& job, vector<int> ability) {
    bool cmp = [](Job x, Job y)->bool{
        return x.hard != y.hard ? (x.hard < y.hard) : (x.money > y.money);

    };
    sort(job.begin(), job.end(), cmp);
    // 难度为key的工作 最优的钱数
    map<int, int> m;
    m[job[0].hard] = job[0].money;
    Job pre = job[0];
    for (int i = 1; i < job.size(); ++i) {
        if (job[i].hard != pre.hard && job[i].money > pre.money) {
            pre = job[i];
            m[pre.hard] = pre.money;
        }
    }
    vector<int> res(job.size());
    for (int i = 0; i < ability.size(); ++i) {
        auto key = m.upper_bound(ability[i]);
        res[i] = key->second;
    }
    return res;
}