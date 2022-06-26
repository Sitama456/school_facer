/**
 * @file 2.4magic集合.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个包含n个整数的集合a,一个包含m个整数的集合b。
 * 定义magic操作为，从一个集合种取出一个元素，放到另一个集合里，且操作过后
 * 每个集合的平均值都大于操作前。注意两点
 * 1) 不可以把一个集合取空，这样就没有平均值了
 * 2) 值为x的元素从集合b取出放入集合a，但集合a中已经有值为x的元素，则a的平均
 * 值不变(因为集合元素不会重复),b的平均值可能会变。
 * 问最多可以进行多少次magic操作
 * 
 */

/**
 * @brief 
 * 1) A B 平均值相等 假设为 100 从 A 拿出数num 到 B 中
 *    a) num > 100 不能拿 A 平均值下降
 *    b) num = 100 不能拿 平均值没变化
 *    c) num < 100 不能拿，B平均值下降
 * 2) A 50 B 100。 不能从A 拿到B，只能 B拿到A,需要满足条件
 *    a) num > 50 && num < 100
 *    b) B不能拿空
 *    c) A中没有num
 * 
 * 贪心: 在大平均值集合里找到符合要求的最小的数
 * 
 */
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

double avg(double sum, int size) {
    return sum / size;
}
/**
 * @brief 
 * 
 * @param arr1 无重复值
 * @param arr2 无重复值
 * @return int 
 */
int maxMagicOps(vector<int> arr1, vector<int> arr2) {
    double sum1 = 0;
    for (int i = 0; i < arr1.size(); ++i) {
        sum1 += (double)arr1[i];
    }
    double sum2 = 0;
    for (int i = 0; i < arr2.size(); ++i) {
        sum2 += (double)arr2[i];
    }
    if (avg(sum1, arr1.size()) == avg(sum2, arr2.size())) {
        return 0;
    }

    vector<int>* arrMore, *arrLess;
    int sumMore, sumLess;
    if (avg(sum1, arr1.size()) > avg(sum2, arr2.size())) {
        arrMore = &arr1;
        sumMore = sum1;
        arrLess = &arr2;
        sumLess = sum2;
    } else {
        arrMore = &arr2;
        sumMore = sum2;
        arrLess = &arr1;
        sumLess = sum1;
    }
    sort(arrMore->begin(), arrMore->end());
    set<int> setLess(arrLess->begin(), arrLess->end());

    int moreSize = arrMore->size();
    int lessSize = arrLess->size();
    int ops = 0;
    for (int i = 0; i < arrMore->size(); ++i) {
        double cur = (double)(*arrMore)[i];
        // 是否符合拿出条件
        if (cur < avg(sumMore, moreSize)
                && cur > avg(sumLess, lessSize)
                && setLess.find(cur) == setLess.end()) {
            sumMore -= cur;
            moreSize--;
            sumLess += cur;
            lessSize++;
            setLess.insert(arrMore->operator[](i));
            ops++;
        }
                
    }
    return ops;

}