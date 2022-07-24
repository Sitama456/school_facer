/**
 * @file HJ34 图片整理.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
Lily上课时使用字母数字图片教小朋友们学习英语单词，每次都需要把这些图片按照大小（ASCII码值从小到大）排列收好。请大家给Lily帮忙，通过代码解决。
Lily使用的图片使用字符"A"到"Z"、"a"到"z"、"0"到"9"表示。

数据范围：每组输入的字符串长度满足 1 \le n \le 1000 \1≤n≤1000 

输入描述：
一行，一个字符串，字符串中的每个字符表示一张Lily使用的图片。

输出描述：
Lily的所有图片按照从小到大的顺序输出
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <random>
using  namespace std;
// 借此机会过一遍排序算法
void bubbleSort(string& s);
void selectSort(string& s);
void insertSort(string& s);
void mergeSort(string& s);
void heapSort(string& s);
void quickSort(string& s);
int main(){
    string inputStr;
    cin >> inputStr;
//     bubbleSort(inputStr);
//     selectSort(inputStr);
//     insertSort(inputStr);
//     mergeSort(inputStr);
//     heapSort(inputStr);
    quickSort(inputStr);
    cout << inputStr;
    
}

// 冒泡排序
void bubbleSort(string& s) {
    int len = s.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (s[i] > s[j]) {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
}

// 选择排序
void selectSort(string& s) {
    int len = s.size();
    int minIndex = -1;
    for (int i = 0; i < len - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < len; ++j) {
            if (s[j] < s[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            char tmp = s[i];
            s[i] = s[minIndex];
            s[minIndex] = tmp;
        }
    }
}

// 插入排序
void insertSort(string& s) {
    int len = s.size();
    for (int i = 1; i < len; ++i) {
        while (i >= 1 && s[i] < s[i - 1]) {
            char tmp = s[i];
            s[i] = s[i - 1];
            s[i - 1] = tmp;
            i--;
        }
    }
}

// 归并排序
void merge(string& s, int l, int mid, int r);
void mergeSortProcess(string& s, int l, int r);
void mergeSort(string& s) {
    mergeSortProcess(s, 0, s.size() - 1);
}
// 在 l ~ r 范围内排序
void mergeSortProcess(string& s, int l, int r) {
    if (l == r) return;
    int mid = l + (r - l) / 2;
    // 左边排序
    mergeSortProcess(s, l, mid);
    // 右边排序
    mergeSortProcess(s, mid + 1,  r);
    // 归并操作
    merge(s, l, mid, r);
}

void merge(string& s, int l, int mid, int r) {
    string tmp;
    tmp.resize(r - l + 1);
    int i1 = l;
    int i2 = mid + 1;
    int count = 0;
    while (i1 <= mid && i2 <= r) {
        // 谁小谁先走
        if (s[i1] <= s[i2]) {
            tmp[count++] = s[i1++];
        } else {
            tmp[count++] = s[i2++];
        }
    }
    
    while (i1 <= mid) {
        tmp[count++] = s[i1++];
    }
    
    while (i2 <= r) {
        tmp[count++] = s[i2++];
    }
    // 将排好序的数组放回去
    for (int i = 0; i < tmp.size(); ++i) {
        s[i + l] = tmp[i];
    }
    
}

// 堆排序
// 小根堆
class myHeap {
public:
    vector<char> datas;
    int size; 
    
    myHeap() : size(0), datas(10) { }
    void insert(char c) {
        if (size == datas.size()) {
            datas.resize(2 * size);
        }
        datas[size] = c;
        heapInsert(size);
        size++;
    }
    
    char pop() {
        swap(0, size - 1);
        char c = datas[size - 1];
        size--;
        //向下调整堆
        heapify(0, size - 1);
        return c;
    }
    
    bool empty() { return size == 0; }
    
    // 从i位置往上调整堆
    void heapInsert(int i) {
        // 跟父亲比较 小就往上冒
        while (datas[i] < datas[(i - 1) / 2]) {
            swap(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }
    
    // 从 i 位置往下调整堆
    void heapify(int i, int end) {
        // 左孩子
        int left = 2 * i + 1;
        while (left <= end) {
            int right = left + 1;
            // 左右孩子中较小的是谁
            int mini = right <= end && datas[right] < datas[left] ? right : left;
            // 和父节点比较 更小的是谁
            mini = datas[i] < datas[mini] ? i : mini;
            if (mini == i) { // 最小的是父节点 不用交换
                break;
            }
            swap(mini, i);
            i = mini;
            left = 2 * i + 1;
        }
    }
    
    void swap(int i, int j) {
        char c = datas[i];
        datas[i] = datas[j];
        datas[j] = c;
    }
};
void heapSort(string& s) {
    myHeap smallRootHeap;
    for (char c : s) {
        smallRootHeap.insert(c);
    }
    int count = 0;
    while (!smallRootHeap.empty()) {
        s[count++] = smallRootHeap.pop();
    }
    
}

// 快速排序
void swap(string& s, int i, int j);
vector<int> partitionString(string& s, char c, int L, int R) {
    // 小于区域
    int leftPart = L - 1;
    // 大于区域
    int rightPart = R + 1;
    int i = L;
    while (i < rightPart) {
        if (s[i] < c) {
            leftPart++;
            swap(s, i, leftPart);
            i++;
        } else if (s[i] > c) {
            rightPart--;
            swap(s, rightPart, i);
        } else {
            i++;
        }
    }
    return { leftPart, rightPart};
    
}

void swap(string& s, int i, int j) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
}

void quickSortProcess(string& s, int L, int R) {
    if (L >= R) return;
    // 取一个随机的位置来作为划分标准
    int randIndex = rand() % (R - L + 1) + L;
    swap(s, randIndex, R);
    vector<int> partition = partitionString(s, s[R], L,  R);
    // 左边去排序
    quickSortProcess(s, L, partition[0]);
    // 右边去排序
    quickSortProcess(s, partition[1], R);
}

void quickSort(string& s) {
    time(NULL);
    quickSortProcess(s, 0, s.size() - 1);
}


