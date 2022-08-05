
#include "a.h"
#include <iostream>
using namespace std;
int test() {
    cout << "var static a in b.cpp : " << &a << endl;
    return 0;
}