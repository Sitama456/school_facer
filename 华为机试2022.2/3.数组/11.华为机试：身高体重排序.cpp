/**
 * @file 11.华为机试：身高体重排序.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 
 /**
  * @brief 
  * 【编程题目 | 100分】身高体重排序 [ 100 / 中等 ]

身高体重排序
题目描述：
某学校举行运动会，学生们按编号(1、2、3…n)进行标识，现需要按照身高由低到高排列，对身高相同的人，按体重由轻到重排列；对于身高体重都相同的人，维持原有的编号顺序关系。请输出排列后的学生编号。

输入描述：
两个序列，每个序列由n个正整数组成（0 < n <= 100）。第一个序列中的数值代表身高，第二个序列中的数值代表体重。。

输出描述：
排列结果，每个数值都是原始序列中的学生编号，编号从1开始，身高从低到高，身高相同体重从轻到重，体重相同维持原来顺序。

示例 1：
输入
4
100 100 120 130
40 30 60 50
1
2
3
输出
2 1 3 4
1
示例 2：
输入
3
90 110 90
45 60 45
1
2
3
输出
1 3 2
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124036720
  */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/**
 * @brief 复习 稳定的排序算法
 * 
 */

struct People {
    int height = 0;
    int weight = 0;
    int id = 0;
    People() {}
    People(int h, int w, int i) : height(h), weight(w), id(i) {}
};

bool sortByHeight(People x, People y) {
    return x.height < y.height;
}

bool sortByWeight(People x, People y) {
    return x.weight < y.weight;
}

void sort(vector<People>& peoples) {
    sort(peoples.begin(), peoples.end(), sortByHeight);
    sort(peoples.begin(), peoples.end(), sortByWeight);
}

int main(int argc, char* argv[]) {
    int n = 0;
    while (1) {
        cin >> n;
        vector<int> heights(n);
        vector<int> weights(n);
        vector<People> peoples(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
        }
        for (int i = 0; i < n; ++i) {
            peoples[i].height = heights[i];
            peoples[i].weight = weights[i];
            peoples[i].id = i + 1;
        }
        sort(peoples);
        for (int i = 0; i < n; ++i) {
             cout << peoples[i].id << " ";
        }
        cout << endl;
    }
    return 0;
}