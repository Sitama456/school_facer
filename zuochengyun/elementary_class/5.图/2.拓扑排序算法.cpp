/**
 * @file 2.拓扑排序算法.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <grath.h>
#include <vector>
#include <queue>
#include <list>
/**
 * 比如依赖问题 比如 A 依赖 B C D ， B 依赖 E F G ...
 *  
 */
list<Node*> sortedTopology(Graph* graph) {

    // key: 某一个node
    // value: 剩余的入度
    map<Node*, int> inMap;
    // 入度为0的点，才能进这个队列
    // 入度为0 表示没有依赖
    queue<Node*> zeroInQueue;
    for (auto& entry : graph->nodes) {
        inMap.insert({entry.second, entry.second->in});
        if (entry.second->in == 0) {
            zeroInQueue.push(entry.second);
        }

    }

    list<Node*> result;
    while (!zeroInQueue.empty())
    {
        Node* cur = zeroInQueue.front();
        zeroInQueue.pop();
        result.push_back(cur);
        // 擦除 cur 的影响
        for (Node* next : cur->nexts) {
            inMap[next]--;
            if (inMap[next] == 0) {
                zeroInQueue.push(next);
            }
        }
        
        
    }
    return result;
    

    
}