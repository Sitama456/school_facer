/**
 * @file HJ19 简单错误记录.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。


处理：


1、 记录最多8条错误记录，循环记录，最后只用输出最后出现的八条错误记录。对相同的错误记录只记录一条，但是错误计数增加。最后一个斜杠后面的带后缀名的部分（保留最后16位）和行号完全匹配的记录才做算是“相同”的错误记录。
2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
3、 输入的文件可能带路径，记录文件名称不能带路径。也就是说，哪怕不同路径下的文件，如果它们的名字的后16个字符相同，也被视为相同的错误记录
4、循环记录时，只以第一次出现的顺序为准，后面重复的不会更新它的出现时间，仍以第一次为准

数据范围：错误记录数量满足 1 \le n \le 100 \1≤n≤100  ，每条记录长度满足 1 \le len \le 100 \1≤len≤100 
输入描述：
每组只包含一个测试用例。一个测试用例包含一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

输出描述：
将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：
 */

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
struct record {
    string name;
    int line = 0;
    int count = 0;
    record(string& name, int line) : name(name), line(line) { }
};

int main(){
    unordered_map<string, record*> mp;
    vector<record*> circleQueue(8, NULL);
    int i = 0;
    string inputStr;
    string fileStr;
    string fileName;
    int line;
    while (cin >> fileStr) {
        cin >> line;
        int fileNamePos = fileStr.find_last_of('\\');
        fileName = fileStr.substr(fileNamePos + 1);
        if (fileName.size() > 16) {
            fileName = fileName.substr(fileName.size() - 16);
        }
        // 是否有同样的记录
        if (mp.find(fileName + to_string(line)) != mp.end()) { // 有
            mp[fileName + to_string(line)]->count++;
        } else { // 没有同样的
            i = i % 8;
            circleQueue[i] = new record(fileName, line);
            circleQueue[i]->count = 1;
            mp.insert({fileName + to_string(line), circleQueue[i]});
            i++;
        }
        
    }
    for (int j = 0; j < circleQueue.size(); ++j) {
        record* rec = circleQueue[(i + j) % 8];
        if (rec) {
            cout << rec->name << " " << rec->line << " "<< rec->count << endl;
        }
    }
    return 0;
}