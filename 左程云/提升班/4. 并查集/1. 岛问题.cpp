/**
 * @file 1. 岛问题.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */



/**
 * @brief 岛问题
 * 一个矩阵中只有0和1两种值，每个位置都可以和自己的上下左右四个位置相连，如果有一片1连在一起，这个部分叫做一个岛。求
 * 一个矩阵中有多少个岛。
 * 进阶：设计一个并行算法解决这个问题。
 * 
 */
#include <vector>
using namespace std;
// 经典做法
void infect(vector<vector<int>>& mat, int i, int j) {
    int m = mat.size();
    int n = mat[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] != 1) {
        return;
    }
    mat[i][j] = 2;
    infect(mat, i + 1, j);
    infect(mat, i - 1, j);
    infect(mat, i, j + 1);
    infect(mat, i, j - 1);
}

int countIslands(vector<vector<int>> mat) {
    int m = mat.size();
    int n = mat[0].size();
    int res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1) {
                res++;
                infect(mat, i, j);
            }
        }
    }
    return res;
}

/**
 * @brief 并查集 给定样本。提供两个操作:
 * 1) 判断元素a和元素b是否在同一个集合
 * 2) 合并a元素和b元素的所在的集合
 * 实现结构：往上指的指针，用代表元素来判断是否同一个集合，并且合并
 */
#include <map>
#include <list>
#include <stack>
template<class T>
class Element {
public:
    T value;
    Element(T value) value(value) {}
};
template<class T>
class UnionFindSet {
public:
    map<T, Element<T>*> elementMap;
    // key-> 某个元素 value 该元素的父
    map<Element<T>*, Element<T>*> fatherMap;
    // 代表元素 代表的集合的元素个数
    map<Element<T>*, int> sizeMap;

    UnionFindSet(list<T>& list) {
        for (T v : list) {
            Element<T>* element = new Element<T>(v);
            elementMap[v] = element;
            fatherMap[element] = element;
            sizeMap[element] = 1;
        }
    }

    bool isSameSet(T a, T b) {
        if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end()) {
            return findHead(elementMap[a]) == findHead(elementMap[b]);
        }
    }

    void Union(T a, T b) {
        if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end()) {
            Element<T>* aF = findHead(elementMap[a]);
            Element<T>* bF = findHead(elementMap[b]);
            if (aF != bF) {
                Element<T>* big = sizeMap[af] >= sizeMap[bF] ? aF : bF;
                Element<T>* small = big == aF ? bF : aF;
                fatherMap[small] = big;
                sizeMap[big] = sizeMap[aF] + sizeMap[bF];
                sizeMap.erase(small);
            }
        }
    }

    Element<T>* findHead(Element<T>* key) {
        stack<Element<T>*> path;
        while (key != fatherMap[key]) {
            path.push(key);
            key = fatherMap[key];
        }
        // 扁平化
        while (!path.empty())
        {
            fatherMap[path.top()] == key;
            path.pop();
        }
        return key;
    }
};

/**
 * @brief 有了并查集后，再设计岛的并行算法
 * 假设一个矩阵切成两半
 *    1 1 1 1 | 1 1 1 1 
 *    0 0 0 0 | 0 0 0 1              
 *    1 0 1 1 | 1 1 1 1
 *    1 0 1 0 | 0 0 0 0
 * 切成两半后，左侧cpu会找到3个岛  右侧cpu会找到1个岛 
 * 所以需要合并
 * 在感染时，如果感染的是边界上的点，记录初始感染点的位置
 * 合并操作：
 * 一开始，各个初始感染点作为一个集合。然后处理边界相碰时的集合合并。
 */  