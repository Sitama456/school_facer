/**
 * @file 2.华为机试：最小传输时延.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 200分】最小传输时延 [ 200 / 中等 ]

题目描述
某通信网络中有N个网络结点，用1到N进行标识。网络通过一个有向无环图表示，其中图的边的值表示结点之间的消息传递时延。
现给定相连节点之间的时延列表times[i]={u，v，w}，其中u表示源结点，v表示目的结点，w表示u和v之间的消息传递时延。
请计算给定源结点到目的结点的最小传输时延，如果目的结点不可达，返回-1。
注：

N的取值范围为[1，100];
时延列表times的长度不超过6000，且 1 <= u,v <= N，0 <= w <= 100;
输入描述


输入的第一行为两个正整数，分别表示网络结点的个数N，以及时延列表的长度M，用空格分隔；
接下来的M行为两个结点间的时延列表[u v w];
输入的最后一行为两个正整数，分别表示源结点和目的结点。
输出描述
起点到终点得最小时延，不可达则返回-1

示例
输入
3 3
1 2 11
2 3 13
1 3 50
1 3
1
2
3
4
5
输出
24
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/125774594
 */
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <iostream>
using namespace std;
struct edge;
struct Node {
    int id = -1; // node 编号
    int in = 0; // 入度个数
    int out = 0; // 出度个数
    
    list<Node*> to; // 改点指向的点
    list<edge*> edges; // 属于该点的边
};

struct edge {
    Node* from = NULL;
    Node* to = NULL;
    int value = 0; // 权值
    edge(Node* f, Node* t, int v) : from(f), to(t), value(v) {

    }
};

struct grath {
    map<int, shared_ptr<Node>> nodes;
    map<int, shared_ptr<edge>> edges;
    int edgesIndex = 0;

    Node* getNodeById(int id) {
        if (nodes.find(id) == nodes.end()) {
            nodes[id].reset(new Node());
            nodes[id]->id = id;
        }
        return nodes[id].get();
    }
    /**
     * @brief 加入点和边 只会调用一次
     * 
     * @param fromId 
     * @param toId 
     * @param weight 
     */
    void add(int fromId, int toId, int weight) {
        Node* fromNode = getNodeById(fromId);
        Node* toNode = getNodeById(toId);
        edges[edgesIndex].reset(new edge(fromNode, toNode, weight));
        fromNode->edges.push_back(edges[edgesIndex].get());
        edgesIndex++;
        fromNode->out++;
        toNode->in++;
    }
};

/**
 * @brief 返回distanceMap中距离最小的节点，不包括已经选择了的
 * 
 * @param distanceMap 
 * @param selected 
 * @return Node* 
 */
Node* getMinDistanceNode(map<Node*, int>& distanceMap, set<Node*>& selected) {
    Node* minNode = NULL;
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
 * @brief Dij 算法 最短路径 
 * 
 * @param grath 
 * @return int 
 */
int minTimeDelay(grath* grath, int formId, int toId) {
    // 表示fromId到各节点的最小距离
    // key : 节点
    // value : 到此节点的最短距离
    map<Node*, int> distanceMap;
    // 已经选择过的节点  不必再选
    set<Node*> selectedNodes;
    Node* head = grath->nodes[formId].get();
    distanceMap[head] = 0;
    // 选出当前 distanceMap中距离最短的节点 一开始就会把head节点选出来
    Node* minNode = getMinDistanceNode(distanceMap, selectedNodes);
    while (minNode != NULL) {
        // 遍历属于它的边
        int distance = distanceMap[minNode];
        for (edge* edge : minNode->edges) {
            // 到达的节点
            Node* to = edge->to;
            // 则head到达to的最小距离就是head--minNode + minNode--to两端
            // 如果没有这条路 就建出来
            if (distanceMap.find(to) == distanceMap.end()) {
                distanceMap[to] = distance + edge->value;
            }
            // 如果值更小 就更新
            distanceMap[to] = min(distanceMap[to], distance + edge->value);
        }
        // head节点到minNode节点的最小距离已经定了 锁住它 别让它在下一轮循环中被选出来
        selectedNodes.insert(minNode);
        minNode = getMinDistanceNode(distanceMap, selectedNodes);
    }
    Node* toNode = grath->nodes[toId].get();

    return distanceMap.find(toNode) == distanceMap.end() ? -1 : distanceMap[toNode];

}

int main(int argc, char* argv[]) {
    int N = 0;
    int M = 0;
    int fromId = 0;
    int toId = 0;
    shared_ptr<grath> g;
    while (1) {
        g.reset(new grath());
        cin >> N;
        cin >> M;
        int u = 0;
        int v = 0;
        int w = 0;
        for (int i = 0; i < M; ++i) {
            cin >> u;
            cin >> v;
            cin >> w;
            g->add(u, v, w);
        }
        cin >> fromId;
        cin >> toId;
        cout << minTimeDelay(g.get(), fromId, toId) << endl;
    }
    return 0;
}