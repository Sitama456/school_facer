/**
 * @file 4.4接雨水.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个数组arr,已知其中所有的值都是非负的，将这个数组看作一个容器，请返回容器能装多少水。
 *
 * 
 */
#include <vector>
using namespace std;

/**
 * @brief 对于i位置来说，左方最高的值，和右方最高的值中的较小的那个，i位置的水量就是
 *  min{max(0...i-1), max(i + 1...n)} - arr[i] ,如果为负数，则取0 比如
 * 10 ) 5 (20 则i位置的水量就是 10 - 5 = 5。这5个格子是肯定不会流走的
 * 利用双指针时可以动态更新i位置的瓶颈，即左右最大值中较小的那个。
 */