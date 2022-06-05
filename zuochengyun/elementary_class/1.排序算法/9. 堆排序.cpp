/*
 * @Description: 
 * @Author: mzm
 * @Date: 2022-05-29 14:37:27
 * @LastEditTime: 2022-05-29 16:15:44
 * @LastEditors: mzm
 */

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


/**
 * @brief 完全二叉树
 * 若设二叉树的深度为h，除第 h 层外，其它各层 (1~h-1) 的结点数都达到最大个数，
 * 第 h 层所有的结点都连续集中在最左边，这就是完全二叉树
 * 数组vector可以对应一棵完全二叉树:
 * i 位置左孩子: 2 * i + 1
 * i 位置右孩子: 2 * i + 2
 * i 位置父节点: (i - 1) / 2
 * 
 * 堆：一种特殊的完全二叉树。
 * 大根堆: 任意一棵子树最大值为头结点
 * 小根堆: 任意一棵子树最小值为头结点
 */
struct heap
{
    vector<int> nums;
    int heapSize;
    
    /**
     * @brief 调整index位置的数 维持堆得结构
     * 
     * @param num 
     */
    void heapInsert(int num, int index) {
        while (nums[index] > nums[(index - 1) / 2]) {
            swap(nums[index], nums[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        heapSize++;
    }
    /**
     * @brief index 位置的数能否往下调整 维持堆的结构
     * 
     * @param index 
     */
    void heapfy(int index) {
        int left = 2 * index + 1;
        while (left < heapSize) {
            // 两个孩子中 较大的是谁 右孩子如果有
            int largerIndex = left + 1 < heapSize && nums[left + 1] > nums[left] ? left + 1 : left;
            // 父节点和孩子结点 谁的值大， 把下标给largerIndex
            largerIndex = nums[index] > nums[largerIndex] ? index : largerIndex;
            if (largerIndex == index) {
                break;
            }
            swap(nums[index], nums[largerIndex]);
            index = largerIndex;
            left = index * 2 + 1;
        }

    }

};



void heapInsert(vector<int>& nums, int index) {
    while (nums[index] > nums[(index - 1) / 2]) {
        swap(nums[index], nums[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapfy(vector<int>& nums, int index, int heapSize) {
    int left = index * 2 + 1;
    while (left < heapSize) {
        int largestIndex = left + 1 < heapSize && nums[left + 1] > nums[left] 
                            ? left + 1 : left;
        largestIndex = nums[index] > nums[largestIndex] ? index : largestIndex;
        if (index == largestIndex) {
            break;
        }
        swap(nums[index], nums[largestIndex]);
        index = largestIndex;
        left = 2 * index + 1;
    }
}

void heapSort(vector<int>& nums) {
    int size = nums.size();
    if (size < 2) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        heapInsert(nums, i);
    }
    int heapSize = size;
    swap(nums[--heapSize], nums[0]);
    while (heapInsert > 0) {
        heapfy(nums, 0, heapSize);
        swap(nums[0], --heapSize);
    }
}

/**
 * @brief 题目
 * 已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离不超过
 * k,并且k相对于数组来说比较小。请选择一个合适的排序算法针对这个数组排序
 * 
 */
// 比较器 [](int x, int y)->int{return x + y;}
//       [](int x, int y)->bool{return x > y;}

void almostSort(vector<int>& nums, int k) {

    // 小根堆只需要放 k + 1 个数字
    // 比较器:
    // true : 第一个参数在前面
    // false : 第一个参数在后面
    bool cmp = [](int x, int y)->bool{return x < y; };
    priority_queue<int, vector<int>, decltype(cmp)> heap;
    int size = nums.size();
    int index = 0;
    for(; index <= min(size, k); index++) {
        heap.push(nums[index]);
    }
    int i = 0;
    for (; index < size; ++i, ++index) {
        heap.push(nums[index]);
        nums[i] = heap.top();
        heap.pop();
    }
    while (!heap.empty()) {
        nums[i++] = heap.top();
        heap.pop();
    }
    
}

/**
 * @brief 一个数据流中，随时可以取得中位数
 * 1) 一个大根堆， 一个小根堆
 * 2) 放入一个数字时，小于等于大根堆顶则入大根堆，否则入小根堆 
 * 3) 比较大根堆和小根堆的size, 相差是否超过2
 *    大根堆size 较大，则弹出大根堆堆顶，否则弹出小根堆堆顶
 */
