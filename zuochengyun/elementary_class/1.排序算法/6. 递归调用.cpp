/*
 * @Description: 
 * @Author: mzm
 * @Date: 2022-05-29 09:08:17
 * @LastEditTime: 2022-05-29 09:38:35
 * @LastEditors: mzm
 */

/**
 * @brief 
 * master 公式：
 * T(N) = a * T(N / b) + o(N^d)
 * a 为主问题调用子问题时的系数 
 * b 为子问题的规模
 * d 为除了递归部分的决策问题的时间复杂度
 * 则递归的时间复杂度为:
 * 1) log(b, a) > d -> 复杂度为 O(N ^ log(b, a))
 * 2) log(b, a) < d -> 复杂度为 O(N ^ d)
 * 3) log(b, a) == d -> 复杂度为 O(N ^ d * log(N))
 */
