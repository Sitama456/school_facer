/**
 * @file 2.RandomPool.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 设计一种结构 在结构中有如下三个功能:
 * 1) insert(key): 将某个key加入到该结构中，做到不重复加入
 * 2) delete(key): 将某个在结构中的key移除
 * 3) getRandom(): 等概率随机返回结构中的一个key 
 * 要求时间复杂度都是O(1)
 * 
 */

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class RandomPool
{
public:
    map<string, int> sToInt;
    map<int, string> intToS;
    int size = 0;
public:
    RandomPool(/* args */) {}
    RandomPool() {}

    void insert(string key) {
        sToInt.insert({key, size});
        intToS.insert({size, key});
        size++;
    }

    void deleteByKey(string key) {
        if (sToInt.find(key) == sToInt.end()) {
            return;
        }
        // 拿最后一条记录去填被删除的洞
        int delIndex = sToInt[key];
        int lastIndex = --size;
        string lastkey = intToS[lastIndex];
        sToInt[key] = lastIndex;
        sToInt.erase(lastkey);
        intToS[delIndex] = lastkey;
        intToS.erase(lastIndex);
    }

    string getRandom() {
        if (size == 0) {
            return "";
        }

        int randNum = rand() % size;
        return intToS[randNum];
    }
};
