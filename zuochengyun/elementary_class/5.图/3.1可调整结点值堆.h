/**
 * @file 3.1可调整结点值堆.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <grath.h>
#include <vector>
#include <map>


/**
 * @brief 可调整结点数值的小根堆
 * 
 */

class NodeHeap {
public:
    class NodeRecord {
    public:
        Node* node;
        int distance;
        NodeRecord(Node* node, int distance) : node(node), distance(distance) {}

    };
public:
    vector<Node*> nodes; // 结点存储结构
    map<Node*, int> heapIndexMap; // 结点 -> 数值索引
    map<Node*, int> distanceMap; // 结点 -> head点到此结点距离
    int size;

    NodeHeap(int size = 0) : size(size) { }

    bool isEmpty() { return size == 0; }
    /**
     * @brief Node 是否进来过
     * 
     * @param node 
     * @return true 
     * @return false 
     */
    bool isEntered(Node* node) {
        return heapIndexMap.find(node) != heapIndexMap.end();
    }
    /**
     * @brief node 结点是否在堆上
     * 
     * @param node 
     * @return true 
     * @return false 
     */
    bool inHeap(Node* node) {
        return isEntered(node) && heapIndexMap[node] != -1; 
    }
    /**
     * @brief 交换结点
     * 
     * @param index1 
     * @param index2 
     */
    void swap(int index1, int index2) {
        heapIndexMap[nodes[index1]] = index2;
        heapIndexMap[nodes[index2]] = index1;
        Node* tmp = nodes[index1];
        nodes[index1] = nodes[index2];
        nodes[index2] = tmp;
    }

    void InsertHeapify(Node* node, int index) {
        // 插入结点与父节点比较 如果比父节点小 则交换
        while (distanceMap[nodes[index]] < distanceMap[nodes[(index - 1) / 2]]) {
            swap(index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }

    void heapify(int index, int size) {
        // 左结点
        int left = index * 2 + 1;
        while (left < size) {
            // 左右结点中选出最小的
            int smallestIndex = left + 1 < size && distanceMap[nodes[left]] < distanceMap[nodes[left + 1]] ?
                        left : left + 1;
            // 跟父结点比较 选出最小的
            smallestIndex = distanceMap[nodes[smallestIndex]] < distanceMap[nodes[index]] ? smallestIndex : index;
            // 父结点最小 不用换 
            if (smallestIndex == index) {
                break;
            }
            // 否则交换父子结点
            swap(index, smallestIndex);
            index = smallestIndex;
            left = index * 2 + 1;
        }
        
    }
    /**
     * @brief 1)如果加入的是新结点，则添加。
     *        2)如果修改的结点值比原来的小，则更新。否则忽略
     * 
     * @param node 
     * @param distance 
     */
    void addOrUpdateOrIgnore(Node* node, int distance) {
        if (inHeap(node)) {
            // 更新distanceMap为最小值
            distanceMap[node] = min(distanceMap[node], distance);
            // 向上更新堆
            InsertHeapify(node, heapIndexMap[node]);
        }
        // 插入新结点
        if (!isEntered(node)) {
            nodes[size] = node;
            heapIndexMap[node] = size;
            distanceMap[node] = distance;
            InsertHeapify(node, size++);
        }
        // 进来过但不在堆上的 直接忽略
    }

    NodeRecord pop() {
        NodeRecord result(nodes[0], distanceMap[nodes[0]]);
        swap(0, size - 1);
        heapIndexMap[nodes[size - 1]] = -1;
        distanceMap.erase(nodes[size - 1]);
        nodes[size - 1] = nullptr;

        heapify(0, --size);
        return result;
    }

    
};