#include <iostream>
#include <vector>
using namespace std;

// 求n的阶乘
int getNum(int n) {
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}


int backtrack(vector<int>& nums, int i, vector<int>& buckets, vector<int>& target, vector<int>& count) {
    // 找到一种放法了
    if (i == nums.size()) {
        // 检查是否有效
        int tmp = 1;
        for (int j = 0; j < buckets.size(); ++j) {
            if (buckets[j] != target[j]) return 0;
            tmp *= getNum(count[j]);
        }
        return tmp;
    }
    int res = 0;
    // 第 i 个展品放在上午还是下午
    for (int j = 0; j < buckets.size(); ++j) {
        if (buckets[j] + nums[i] <= target[j]) {
            buckets[j] += nums[i];
            count[j]++;
            res += backtrack(nums, i + 1, buckets, target, count);
            count[j]--;
            buckets[j] -= nums[i];
        }
    }
    return res;
} 

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<int> bucket(2, 0);
    vector<int> target = {60, 120};
    vector<int> count(2, 0);
    cout << backtrack(nums, 0, bucket, target, count) << endl;
}


#define N 5
#define LEFT (i + N - 1) % N
#define RIGHT (i + 1) % N 
#define THINKING 0
#define HUNGRY 1
#define EATING 2

typedef int semaphore;
int state[N]; // 跟踪每个哲学家的状态
semaphore mutex = 1; // 保护state的临界区
semaphore s[N]; // 每个哲学家一个信号量

void think(int i);
void take_two(int i);
void eat(int i);
void put_two(int i);
void down(int* num);
void up(int* num);
void check(int i);


void philosopher(int i) {
    while (true) {
        think(i);
        take_two(i);
        eat(i);
        put_two(i);
    }
}

void take_two(int i) {
    // 修改状态为hungry
    down(&mutex);
    state[i] = HUNGRY;
    check(i);
    up(&mutex);
    down(&s[i]); // 只有收到通知才可以吃
}

void put_two(int i) {
    down(&mutex);
    state[i] = THINKING;
    check(LEFT); // 尝试通知左右邻居 我以及吃完了
    check(RIGHT);
    up(&mutex);
    down(&s[i]);
}

void eat(int i) {
    down(&mutex);
    state[i] = EATING;
    up(&mutex);
}

// 检查左右两个邻居是否都没有用餐
void check(int i) {
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        up(&s[i]);
    }
}
