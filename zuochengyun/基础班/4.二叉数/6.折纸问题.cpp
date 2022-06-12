/**
 * @file 6.折纸问题.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/**
 * 请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对着1次，压出折痕后展开。
 * 此时折痕是凹下去的，即折痕突起的方向指向纸条的背面。
 * 如果从纸条的下边向上方连续对折2次，压出折痕后展开，此时有三条折痕，从上
 * 到下一次是下折痕、下折痕和上折痕
 * 给定一个输入参数N，代表纸条都从下边向上连续对折N次，请从上到下打印所有折痕的方向。
 * 
 */
/**
 * 实际上形成了总头节点为凹折痕， 每个左子树的头节点为凹 每个右子树的头节点为凸
 * 
 */
#include <stdlib.h>
#include <iostream>
using namespace std;
void printProcess(int i, int N, bool down);
void printAllFolds(int N) {
    printProcess(1, N, true);
}

/**
 * @brief 第 i 层的节点是否为凹
 * 
 * @param i 第 i 层
 * @param N 总共 N 层
 * @param down 是否为凹
 */
void printProcess(int i, int N, bool down) {
    if (i > N) {
        return;
    }
    printProcess(i + 1, N, true);
    cout << (down ? "凹" : "凸") << endl;
    printProcess(i + 1, N, false);
    
}