/**
 * @file 41.数据流中的中位数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <queue>
using namespace std;
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        // 如果两个堆个数一样 则往大根堆丢一个
        // 但要确保大根堆中的数据都是小于等于小根堆的
        if (bigRootQueue.size() == smallRootQueue.size()) {
            smallRootQueue.push(num);
            bigRootQueue.push(smallRootQueue.top());
            smallRootQueue.pop();
        } else { // 大根堆数据多了
            bigRootQueue.push(num);
            smallRootQueue.push(bigRootQueue.top());
            bigRootQueue.pop();
        }
    }
    
    double findMedian() {
        if (bigRootQueue.size() == smallRootQueue.size()) {
            return (bigRootQueue.top() + smallRootQueue.top()) / 2.0;
        } else {
            return bigRootQueue.top();
        }
    }

private:
    
    // 大根堆 堆顶为最大元素 存储小于的一半
    priority_queue<int, vector<int>, greater<int>> bigRootQueue;
    priority_queue<int, vector<int>, less<int>> smallRootQueue;
    int size = 0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */