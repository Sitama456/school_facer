/*** 
 * @Author: mzm
 * @Date: 2022-06-01 21:51:30
 * @LastEditTime: 2022-06-01 23:00:48
 * @LastEditors: mzm
 * @Description: 
 * @FilePath: /zuochengyun/5.图/grath.h
 * @
 */
/**
 * @file 1.图存储方式.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 邻接表
 * 
 *  A ---- B
 *  | \    |
 *  |   \  |
 *  C ---- D
 * 以点集为单位，每个点记录直接邻居 例如
 * A : B C D
 * B : A D
 * C : A D
 * D : A C B 
 * 路线中存储了信息 有向图 和 无向图
 */
#include <map>
#include <vector>
#include <list>
using namespace std;
class Edge;
class Node {
public:
    int value; // 节点的值
    int in; // 入度个数：有多少个点发散出来的边指向该点
    int out; // 出度个数: 该点发散的边指向多少个点
    list<Node*> nexts; // 发散出去的边(出度边) 直接相连的点
    list<Edge*> edges; // 属于该点的边

    Node(int value, int in = 0, int out = 0) : value(value), in(in), out(out) {}

};

/**
 * @brief 有向边
 * 
 */
class Edge {
public:
    int weight; // 权值
    Node* from;
    Node* to;
    Edge(int weight) : weight(weight), from(nullptr), to(nullptr) {}

};

class Graph {
public:
    map<int, Node*> nodes; // 点集: 编号->点
    map<int, Edge*> edges; // 边集: 编号->边

    Graph() {

    }
};