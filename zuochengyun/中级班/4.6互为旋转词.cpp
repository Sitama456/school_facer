/**
 * @file 4.6互为旋转词.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 如果一个字符串为str， 把字符串str前面任意的部分挪到后面的字符串叫做
 * str的旋转词。给定两个字符串a和b，请判断a和b是否互为旋转词
 * 
 */

/**
 * @brief 
 * 1. a b 长度是否一致
 * 2. 生成 a + a, 看 b是否是 a + a 的字串。因为 a + a 中任意长度为N的字串
 * 必定是a的旋转词
 * 
 */