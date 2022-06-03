/*
 * @Description: 
 * @Author: mzm
 * @Date: 2022-05-29 18:23:52
 * @LastEditTime: 2022-05-29 19:01:29
 * @LastEditors: mzm
 */

/**
 * @brief 排序算法稳定性
 * 同样值得个体之间，如果不因为排序而改变相对次序，就称这个排序是有稳定性的，否则就没有
 * 
 * 不具有稳定性的排序算法：
 * 1) 选择排序 时间 O(N ^ 1) 空间 O(1)
 *      例如: 3 3 1 3 3 第一次就会把第一个3和1交换
 * 2) 快速排序 时间 O(N * logN) 空间 O(logN)
 *      例如 6 7 6 6 3   划分值为 5 ; 第一个 6 会和 3 交换
 * 3) 堆排序 时间 O(N * logN) 空间 O(1)
 *      例如 5 4 4 6 ... 则 6 要 和 4 交换，就破坏了稳定性了
 * 
 * 具有稳定性的排序:
 * 1) 冒泡排序  O(N ^ 2) O(1)
 *      例如 6 5 3 2 4 7 6 相等的数不交换
 * 2) 插入排序 O(N ^ 2) O(1)
 *      例如 3 2 2 ... -> 2 3 2 ... -> 2 2 3 也是相等的数不交换
 * 3) 归并排序 O(N ^ 2) O(N)
 *      例如 1 4 5 | 1 4 6 merge 时，相等数左边先拷贝
 * 4) 桶排序
 *      不基于比较的排序 只需规定出桶入桶的规则就可以保证稳定性
 */

/**
 * @brief 工程上对排序算法的改进
 * 1) 充分利用 O(N * logN) 和 O(N ^ 2) 各自的优势。即在某些范围内用 O(N ^ 2) 的排序算法。
 * 2) 稳定性的考虑。
 */