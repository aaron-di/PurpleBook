/*
由于string已经定义了“小于”运算符， 直接使用set保存单词集合即可。注意，输入时把所有非字母的字符变成空格，然后利用
stringstream得到各个单词。
*/

#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

set<string> dict;  // string集合

int main() {
    string s, buf;
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {  //把所有非字母的字符变成空格，字母全部换成小写
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
            } else {
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        while (ss >> buf) {
            dict.insert(buf);
        }
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
