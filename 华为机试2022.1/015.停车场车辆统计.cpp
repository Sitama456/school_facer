/**
 * @file 015.停车场车辆统计.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * https://blog.csdn.net/weixin_37580235/article/details/125130642
 */


#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief 0 ~ i - 1 位置不管， i ~ size的车辆有多少
 * 
 * @param cars 
 * @param i 
 * @return int 
 */
int minCarNums(vector<int>& cars, int i) {
    if (i == cars.size()) {
        return 0;
    }
    // 当前没有停车
    if (cars[i] == 0) {
        return minCarNums(cars, i + 1);
    }
    // 当前停的小车
    int res1 = __INT_MAX__;
    int res2 = __INT_MAX__;
    int res3 = __INT_MAX__;
    
    res1 = 1 + minCarNums(cars, i + 1);
    // 当前停的货车
    if (i + 1 < cars.size() && cars[i + 1] == 1) {
        res2 = 1 + minCarNums(cars, i + 2);
        // 当前停的卡车
        if (i + 2 < cars.size() && cars[i + 2] == 1) {
            res3 = 1 + minCarNums(cars, i + 3);
        }
    }
    return min(res1, min(res2, res3));
    
}
#include <string>
#include <string.h>
#include <iostream>
int main() {
    vector<int> cars;
    string inputStr;
    while (1) {
        cars.clear();
        cin >> inputStr;
        char* tmp = strtok((char*)inputStr.data(), ",");
        while (tmp != NULL) {
            cars.push_back(atoi(tmp));
            tmp = strtok(NULL, ",");
        }
        cout << minCarNums(cars, 0) << endl;
    }

}