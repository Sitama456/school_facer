/**
 * @file 3.4最多出现次数.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个字符串类型的数组arr, 求其中出现次数最多的前K个
 * 
 */

/**
 * @brief 
 * 1) 遍历arr，建立词频表 加入到大根堆中
 * 2） 弹出前K个
 * 
 * // 或者 建立小根堆  小根堆的size 不超过 K，目前遍历到的前k个 即门槛
 */


/**
 * @brief 实现一种结构，实时显示目前的topK 支持两种操作
 * 1) add     加入元素
 * 2) print   实时显示
 * 
 * 
 */

/**
 * @brief 
 * 1) 词频表 key : str -> value : num
 * 2) 堆，长度为k
 * 3) 位置表 : key : str -> value : 堆中的索引 index 
 * 
 */
#include <vector>
#include <map>
#include <string>
#include <memory>
using namespace std;

class Node {
public:
    string str;
    int times;

    Node(string s, int t) : str(s), times(t) {

    }
    
};

class TopKRecord {
public:
    map<string, shared_ptr<Node>> strNodeMap;
    vector<Node*> heap; // 小根堆
    map<Node* , int> nodeIndexMap; // 索引表
    int index; // 堆大小

    TopKRecord(int K) {
        heap.resize(K);
        index = 0;
    }

    void add(string str) {
        Node* curNode = nullptr;
        int preIndex = -1;
        // 如果没加过
        if (strNodeMap.find(str) == strNodeMap.end()) {
            curNode = new Node(str, 1);
            strNodeMap[str].reset(curNode);
            nodeIndexMap[strNodeMap[str].get()] = -1;
        } else {
            curNode = strNodeMap[str].get();
            curNode->times++;
            preIndex = nodeIndexMap[strNodeMap[str].get()];
        }
        // 不在堆上
        if (preIndex == -1) {
            // 堆满了
            if (index == heap.size()) {
                if (heap[0]->times < curNode->times) {
                    // 干掉门槛了
                    nodeIndexMap[heap[0]] = -1;
                    nodeIndexMap[strNodeMap[str].get()] = 0;
                    heap[0] = strNodeMap[str].get();
                    heapify(0, index);
                }
            } else {
                nodeIndexMap[strNodeMap[str].get()] = index;
                heap[index] = strNodeMap[str].get();
                heapInsert(index++);
            }
        } else {// 在堆上
            // 当前位置往下沉
            heapify(preIndex, index);
        }
    }

    void heapify(int i, int end) {
        // 左右孩子
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        while (l < index) {
            // 两个孩子中较小的是谁
            int smallest = r < index && heap[r]->times < heap[l]->times ? r : l;
            // 孩子与父亲比较 较小的是谁
            smallest == heap[smallest]->times < heap[i]->times ? smallest : i;
            // 如果最小的是 i 即父亲 则不用沉
            if (smallest == i) {
                break;
            }
            // 交换
            swap(i, smallest);
            i = smallest;
            l = i * 2 + 1;
            r = i * 2 + 2;
        }
    }

    void heapInsert(int i) {
        // 与父亲节点比较
        while (i != 0) {
            int parent = (i - 1) / 2;
            if (heap[i]->times < heap[parent]->times) {
                swap(i, parent);
                i = parent;
            } else {
                break;
            }
        }
        
    }

    void swap(int i, int j) {
        // 交换index
        Node* nodei = heap[i];
        Node* nodej = heap[j];
        nodeIndexMap[nodei] = j;
        nodeIndexMap[nodej] = i;
        std::swap(heap[i], heap[j]);
    }

};