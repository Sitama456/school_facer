/**
 * @file 2.买苹果.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 小虎去买苹果，只提供6个每袋和8个每袋的包装袋装。小虎想买n个苹果，请返回
 * 最小使用的袋子数量
 * 
 */

#include <vector>
using namespace std;
int minBagBase6(int rest) {
    return rest % 6 == 0 ? rest / 6 : -1;
}
int getBags(int apples) {
    if (apples% 2)  {
        return -1;
    }

    int bag6 = -1;
    int bag8 = apples / 8;
    int rest = apples - 8 * bag8;
    while (bag8 >= 0 && rest < 24) {
        int restUse6 = minBagBase6(rest);
        if (restUse6 != -1) {
            return bag8 + restUse6;
        }
        bag8--;
        rest = apples - 8 * bag8;
    }
    return -1;
}

/**
 * @brief 牛羊吃草，每次只能吃 4 的幂次方草。给定n份草，谁先吃完最后一份草谁赢。
 * 
 */
#include <string>
using namespace std;

string winner1(int n) {
    if (n < 5) {
        return (n == 0 || n == 2) ? "后手" : "先手";
    }
    // n >= 5 时 先手从 1 份草开始
    int base = 1;
    // n - base 份草让后手去吃 则在子过程中，先手是后手
    while (base <= n) {
        if (winner1(n - base) == "后手") {
            return "先手";
        }
        if (base > n / 4) { // 防止 base * 4 之后溢出
            break;
        }
        base *= 4;
    }
    // 没有一种方法可以使我赢 就是后手赢了
    return "后手";
}

/**
 * @brief 打印 n 从 0 到 50，发现规律为 后先后先先 后先后先先 后先后先先...
 * 打表法: 输入参数很简单，输出参数也很简单。写一个很傻的算法，打表查看规律
 * 
 */

