#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getAwards(string& s1, string& s2) {
    int res = 0;
    int i = 0;
    int j = 0;
    while (i <= s1.size() && j <= s2.size()) {
        if (s1[i] == s2[j]) {
            res++;
        }
        i++;
        j++;
    }
    return res * 2;
} 

int main() {
    string inputStr1;
    string inputStr2;
    cin >> inputStr1;
    cin >> inputStr2;
    cout << getAwards(inputStr1, inputStr2) << endl;
    return 0;
}