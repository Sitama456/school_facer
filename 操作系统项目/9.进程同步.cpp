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


// 读者写者问题
typedef int semaphore;
int count = 0; // 记录对数据进行读操作的进程数量
semaphore count_mutex = 1; // 保护count的锁
semaphore data_mutex = 1; // 保护数据的锁

void read();
void write();

void reader() {
    while(true) {
        // 读者进来
        down(&count_mutex);
        count++;
        if (count == 1) down(&data_mutex); // 第一个读者需要对数据进行加锁
        up(&count_mutex);
        read();
        // 读者出去
        down(&count_mutex);
        count--;
        if (count == 0) up(&data_mutex); // 最后一个读者对数据解锁
        up(&count_mutex);

    }
}

void writer() {
    while(true) {
        down(&data_mutex);
        write();
        up(&data_mutex);
    }
}