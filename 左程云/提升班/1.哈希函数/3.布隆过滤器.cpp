/**
 * @file 3.布隆过滤器.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 布隆过滤器解决类似黑名单问题 去重
 * 1) 有100亿个url组成的黑名单，每个url最多64个字节
 * 2) 给定一个url，判断是否在黑名单里。黑名单不用支持删除功能
 * 布隆过滤器就是建立一个集合，只有add和check功能，没有删除，并且误判。一个url可能是白名单的，
 * 也给误判为黑的了，错杀了。可以通过某些措施使失误率很低。
 * 
 */

#include <vector>
using namespace std;
/**
 * @brief 位图 下标从零开始
 * 
 */
class BitArray {
public:
    vector<int> nums;

    int getBitState(int index) {
        int numIndex = index / 32;
        int bitIndex = index % 32;
        if (numIndex >= nums.size()) {
            return 0;
        } 
        return (nums[numIndex] >> bitIndex) & 1;
    }

    void setBitState(int index, int state) {
        state = state == 0 ? 0 : 1;
        int numIndex = index / 32;
        int bitIndex = index % 32;
        if (numIndex >= nums.size()) {
            nums.resize(numIndex * 1.5);
        } 
        if (state == 1) {
            nums[numIndex] = nums[numIndex] | (1 << bitIndex);
        } else {
            nums[numIndex] = nums[numIndex] & (~(1 << bitIndex));
        }
    }


};