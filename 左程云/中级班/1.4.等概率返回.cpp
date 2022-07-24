/**
 * @file 4.等概率返回.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个函数f，可以等概率返回1~5。请加工处等概率返回1~7中的一个函数g
 * 
 * 给定一个函数f，可以等概率返回a~b。请加工出等概率返回c~d的一个函数g
 * 
 * 
 * 给定一个函数f，以p概率返回0, 以1-p概率返回1。请加工出等概率返回0和1的函数
 * roll 两会 f。得到 00 11 重做 01 10则分别返回 0 和 1
 * 
 */

// 等概率返回0~5
int f05() {
    return 0;
}

// 等概率返回 0 和 1
int f01() {
    int num = 0;
    do {
        num = f05();
    }while(num == 3);
    return num < 3 ? 0 : 1;
}

// 等概率返回1 ~ 7