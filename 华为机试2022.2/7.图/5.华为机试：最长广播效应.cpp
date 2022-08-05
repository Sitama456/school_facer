/**
 * @file 5.华为机试：最长广播效应.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <stack>

using namespace std;

struct Node {
    int id = -1;
    list<Node*> nexts;
};

struct Graph {
    map<int, shared_ptr<Node>> nodes;

    Node* getNodeById(int id) {
        if (nodes.find(id) == nodes.end()) {
            nodes[id].reset(new Node());
            nodes[id]->id = id;
        }
        return nodes[id].get();
    }

    void add(int u, int v) {
        Node* nodeU = getNodeById(u);
        Node* nodeV = getNodeById(v);
        nodeU->nexts.push_back(nodeV);
        nodeV->nexts.push_back(nodeU);
    }
};


Node* getMinNode(map<Node*, int>& distanceMap, set<Node*>& selected) {
    Node* minNode = nullptr;
    int minDistance = INT32_MAX;
    for (auto& entry : distanceMap) {
        Node* node = entry.first;
        int distance = entry.second;
        if (selected.find(node) == selected.end() && minDistance > distance) {
            minNode = node;
            minDistance = distance;
        }
    }
    return minNode;
}

/**
 * @brief 在最小路径中找最大的
 * 
 * @param graph 
 * @param sourceId 
 * @return int 
 */
int maxDistance(Graph* graph, int sourceId) {
    map<Node*, int> distanceMap;
    set<Node*> selected;

    Node* sourceNode = graph->getNodeById(sourceId);
    distanceMap[sourceNode] = 0;
    Node* minNode = getMinNode(distanceMap, selected);
    while (minNode != NULL) {
        int distance = distanceMap[minNode];
        for (Node* next : minNode->nexts) {
            if (distanceMap.find(next) == distanceMap.end()) {
                distanceMap[next] = distance + 1;
            }
            distanceMap[next] = min(distanceMap[next], distance + 1);
        }
        selected.insert(minNode);
        minNode = getMinNode(distanceMap, selected);
    }
    int res = 0;
    for (auto& entry : distanceMap) {
        if (entry.first != sourceNode && entry.second > res) {
            res = entry.second;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    int N = 0;
    int T = 0;
    shared_ptr<Graph> graph;
    while (1) {
        graph.reset(new Graph());
        cin >> N;
        cin >> T;
        int u = 0;
        int v = 0;
        for (int i = 0; i < T; ++i) {
            cin >> u;
            cin >> v;
            graph->add(u, v);
        }
        int sId;
        cin >> sId;
        cout << 2 * maxDistance(graph.get(), sId) << endl;
    }
    return 0;
}