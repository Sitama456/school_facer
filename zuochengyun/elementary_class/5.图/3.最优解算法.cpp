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

/**
 * @brief Dijkstra 算法 指定从某个点出发，到其他点的最短到达距离 适用于没有累加和为负数的环
 * 
 */
bool hasEntry(set<Node*>& s, Node* entry) {
    return s.find(entry) != s.end();
}

Node* getMinDistanceAndUnselectedNode(map<Node*, int>& distanceMap, set<Node*>& selectedNodes);
map<Node*, int> dijkstra1(Node* head) {
    // 从head出发到所有点的最小距离
    // key : 从 head出发到达key
    // value : 从 head 出发到达 key 的最短距离
    // 如果在表中，没有 T 的记录，含义是从 head 出发到T这个点的距离为正无穷。
    map<Node*, int> distanceMap;
    distanceMap[head] = 0;
    // 已经求过距离的点 在 selectedNodes 中，再也不碰
    set<Node*> selectedNodes;
    // 一开始会把头节点选出来
    Node* minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
    while (minNode != nullptr) {
        int distance = distanceMap[minNode];
        for (Edge* edge : minNode->edges) {
            // minNode -> toNode 的距离等于原距离加上 edge->weight
            Node* toNode = edge->to;
            // 如果让原来没路的节点有路 就新增
            if (!hasEntry(selectedNodes, toNode)) {
                distanceMap.insert({toNode, distance + edge->weight});
            } 
            // 如果让原来的路更短 就更新
            distanceMap.insert({toNode, min(distanceMap[toNode], distance + edge->weight)});
        }
        // 选出了 head->minNode 的最短距离 锁住
        selectedNodes.insert(minNode);
        minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
    }
    return distanceMap;
    
}

/**
 * @brief 找出当前 distanceMap 中的最短距离 忽略已经 selected 的值
 * 
 * @param distanceMap 
 * @param selectedNodes 
 * @return Node* 
 */
Node* getMinDistanceAndUnselectedNode(map<Node*, int>& distanceMap, set<Node*>& selectedNodes) {
    Node* minNode = nullptr;
    int minDistance = INT32_MAX;
    for (auto& entry : distanceMap) {
        Node* node = entry.first;
        int distance = entry.second;
        if (selectedNodes.find(node) == selectedNodes.end() && distance < minDistance) {
            minNode = node;
            minDistance = distance;
        }
    }
    return minNode;
}