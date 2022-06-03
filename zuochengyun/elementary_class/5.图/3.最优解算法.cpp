/**
 * @file 3.最优解算法.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <grath.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

/**
 * @brief kruskalMST 每条边的值代表代价，如何用最小代价连接所有节点
 * 1) 从最小边出发，如果加入这条边没有形成环，就加入
 * 2) 难点就在于如何判断是不是会形成环, 使用集合，一个集合里的就会形成环
 * 
 */

class MySets{
public:
    map<Node*, list<Node*>*> setMap;
    MySets(list<Node*> nodes) { 
        for (Node* cur : nodes) {
            list<Node*>* set = new list<Node*>();
            set->push_back(cur);
            setMap.insert({cur, set});
        }
    }
    bool isSameSet(Node* from, Node* to) {
        list<Node*>* fromSet = setMap[from];
        list<Node*>* toSet = setMap[to];
        return fromSet == toSet;

    }
    void unionSet(Node* from, Node* to) {
        list<Node*>* fromSet = setMap[from];
        list<Node*>* toSet = setMap[to];
        for (Node* toNode : *toSet) {
            fromSet->push_back(toNode);
            setMap[toNode] = fromSet;
        }

    }
};

set<Edge*> kruskalMST(Graph* graph) {
    list<Node*> listSet;
    for (auto& i : graph->nodes) {
        listSet.push_back(i.second);
    }
    MySets* mysets = new MySets(listSet);
    bool cmp = [](Edge* x, Edge* y)->bool{return x->weight > y->weight;};
    priority_queue<Edge*, vector<Edge*>, decltype(cmp)> priorityQueue;
    for (auto& edge : graph->edges) {
        priorityQueue.push(edge.second);
    }
    set<Edge*> result;
    while (!priorityQueue.empty()) {
        Edge* edge = priorityQueue.top();
        priorityQueue.pop();
        if (!mysets->isSameSet(edge->from, edge->to)) { // 如果不是一个集合 则无环
            result.insert(edge);
            mysets->unionSet(edge->from, edge->to);
        }
    }
    return result;

}

/**
 * @brief p 算法 从点的角度考虑
 * 
 */

set<Edge*> primMst(Graph* graph) {
    // 解锁的边进入小跟堆
    bool cmp = [](Edge* x, Edge* y)->bool{ return x->weight < y->weight;};
    priority_queue<Edge*, vector<Edge*>, decltype(cmp)> queue1;
    set<Node*> NodeSet;
    set<Edge*> result;
    for (auto entry : graph->nodes) { // 兼顾各个大区域不联通
        // node 是开始点
        if (NodeSet.find(entry.second) == NodeSet.end()) {
            NodeSet.insert(entry.second);
            // 由一个点，解锁所有相连的边
            for (Edge* edge : entry.second->edges) {
                queue1.push(edge);
            }
            while (!queue1.empty()) {
                Edge* edge = queue1.top();
                queue1.pop();
                Node* toNode = edge->to;
                // 如果要去的点没在集合里
                if (NodeSet.find(toNode) == NodeSet.end()) {
                    NodeSet.insert(toNode);
                    result.insert(edge);
                    for (Edge* nextEdge : toNode->edges) {
                        queue1.push(nextEdge);
                    }

                }
            }
        }
    }
    return result;
    
}