/**
 * @file 2.汉诺塔问题.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 汉诺塔问题
 * 1) 有三个竿 左 中 右 n个圆盘一开始在左边，移到右边
 * 2) 移动过程中不能出现大压小
 * 求最少的步数
 * 
 * 求解思路：抽象为 从 from 到 to, other 为另一根竿
 * 1) 1 ~ i - 1 从from移动到other
 * 2) i 从 from 移动到 to
 * 3) 1 ~ i - 1 从 other 到 to 
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;



void func(int i, string start, string end, string other) {
    if (i == 1) {
        cout << "Move 1 from " << start << " to " << end << endl;
        return;
    }
    // 1 ~ i - 1 移动到 other
    func(i - 1, start, other, end);
    // i 移动到 to 
    cout << "Move " << i << "from " << start << " to " << end << endl;
    // 1 ~ i - 1 移动到 to 
    func(i - 1, start, end, other);

}

void hanot(int n) {
    func(n, "左", "右", "中");
}

