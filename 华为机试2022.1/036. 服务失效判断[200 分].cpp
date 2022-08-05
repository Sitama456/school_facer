/**
 * @file 036. 服务失效判断[200 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125175079
 * 
 */
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <memory>
#include <iostream>
using namespace std;
// 图节点 表示一个服务器
class Edge;
class Node {
public:
    string name; // 服务器编号
    int in; // 入度个数
    int out; // 出度个数
    vector<Node*> nexts; // 出度边 发散出去的边 相连的点
    // vector<Edge*> edges; // 属于该节点的边
    Node(string name, int in, int out) : name(name), in(in), out(out) {}
};

// 有向边
class Edge {
public:
    Node* from = NULL;
    Node* to = NULL;
    Edge(Node* from, Node* to) : from(from), to(to) {}
};

class Grath {
public:
    map<string, shared_ptr<Node>> nodes; // 点集 名字->点 
    // map<int, shared_ptr<Edge>> edges; // 边集 编号->边

    bool hasNode(string name) {
        return nodes.find(name) != nodes.end();
    }
    Node* getNode(string name) {
        if (!hasNode(name)) {
            nodes[name].reset(new Node(name, 0, 0));
        }
        return nodes[name].get();
    }
    Grath() { }
    ~Grath() {}
    

    
};


vector<string> getWorkServer(Grath* graph, queue<string>& wrongServer) {
    // 从坏掉的服务出发 查看其他因此坏掉的服务
    set<Node*> allWrong;
    while (!wrongServer.empty()) {
        Node* node = graph->getNode(wrongServer.front());
        wrongServer.pop();
        allWrong.insert(node);
        for (Node* toNode : node->nexts) {
            wrongServer.push(toNode->name);
        }
    }
    vector<string> res;
    for (auto& entry : graph->nodes) {
        if (allWrong.find(entry.second.get()) == allWrong.end()) {
            res.push_back(entry.first);
        }
    }
    return res;
}

Grath* buildGraph(vector<string>& dependencies) {
    Grath* graph = new Grath();
    for (string& str : dependencies) {
        int pos = str.find('-');
        string name1 = str.substr(0, pos);
        string name2 = str.substr(pos + 1);
        Node* node1 = graph->getNode(name1);
        Node* node2 = graph->getNode(name2);
        node2->nexts.push_back(node1);
    }
    return graph;
}

int main() {
    string inputStr;
    while (1) {
        cin >> inputStr;
        vector<string> strs;
        char *tmp = strtok((char*)(inputStr.data()), ",");
        while (tmp != NULL) {
            strs.push_back(tmp);
            tmp = strtok(NULL, ",");
        }
        Grath* graph = buildGraph(strs);
        queue<string> wrongServer;
        cin >> inputStr;
        tmp = strtok((char*)(inputStr.data()), ",");
        while (tmp != NULL) {
            wrongServer.push(tmp);
            tmp = strtok(NULL, ",");
        }
        vector<string> workServer = getWorkServer(graph, wrongServer);
        for (string& server : workServer) {
            cout << server << ",";
        }
        cout << endl;
        delete graph;
    }
}