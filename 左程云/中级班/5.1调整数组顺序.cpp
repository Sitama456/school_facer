/**
 * @file 5.1调整数组顺序.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个数组，可以通过调整元素顺序，让任意相邻两个数是4的倍数。能够调整
 * 返回true，否则返回false
 * 
 */

/**
 * @brief 遍历数组，将数分为三种数
 * 1) 奇数 a个
 * 2) 只有一个2因子的偶数 b个
 * 3) 包含4因子的数 c个
 * 
 * 1、b == 0。 奇4奇4... a==1  c >= 1;  a > 1, c >= a - 1
 * 2、b != 0  
 *      b > 1 :22 22 22 2 22 奇4奇4....   a = 0, c >= 0; a = 1, c >= 1; a > 1, c >= a
 *      b == 1 : 
 */