/**
 * @file 5.5零食背包.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 背包容量为w，一共n袋零食，第i袋零食体积为v[i]。
 * 问总体积不超过背包容量的前提下，一共有多少种零食方法(总体积为0也是一种放法)
 * 
 */

/**
 * @brief 
 * dp[i][j] : arr[0...i]上的数字自由使用，但每个数字最多只能使用一次，累加
 * 和正好为j的方法数。
 * 
 */