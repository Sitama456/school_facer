/**
 * @file 剑指 Offer II 030. 插入、删除和随机访问都是 O(1) 的容器.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构：

insert(val)：当元素 val 不存在时返回 true ，并向集合中插入该项，否则返回 false 。
remove(val)：当元素 val 存在时返回 true ，并从集合中移除该项，否则返回 false 。
getRandom：随机返回现有集合中的一项。每个元素应该有 相同的概率 被返回。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/FortPu
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <map>
#include <algorithm>

using namespace std;
class RandomizedSet {
public:
    int size = 0;
    map<int, int> indexs;
    map<int, int> values;

    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (indexs.find(val) != indexs.end()) {
            return false;
        }
        values[size] = val;
        indexs[val] = size;
        size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (indexs.find(val) == indexs.end()) {
            return false;
        }
        // 要删除的index
        int oldIndex = indexs[val];
        // 要替换的val
        int newVal = values[size - 1];
        indexs[newVal] = oldIndex;
        values[oldIndex] = newVal;

        indexs.erase(val);
        values.erase(size - 1);
        size--;
        return true;

    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int num = rand() % size;
        return values[num];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */