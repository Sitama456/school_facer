/**
 * @file 3.4最多出现次数.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个字符串类型的数组arr, 求其中出现次数最多的前K个
 * 
 */

/**
 * @brief 
 * 1) 遍历arr，建立词频表 加入到大根堆中
 * 2） 弹出前K个
 * 
 * // 或者 建立小根堆  小根堆的size 不超过 K，目前遍历到的前k个 即门槛
 */