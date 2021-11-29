#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> cnt;  //用一个map记录单词出现的次数
vector<string> words;  //vector用来存所有的输入字符

//将单词s进行标准化
string restandard(const string& s) {
    string ans = s;
    for (int i = 0; i < ans.length(); i++) {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n = 0;
    string s;
    while (cin >> s) {
        if (s[0] == '#') {
            break;
        }
        words.push_back(s);
        string r = restandard(s);
        if (!cnt.count(r)) {
            cnt[r] = 0;
        }
        cnt[r]++;
    }
    vector<string> ans;
    for (int i = 0; i < words.size(); i++) {
        if (cnt[restandard(words[i])] == 1) {  //如果map中标准化后的字符串所对应的value为1，说明出现了一次，即为所求值
            ans.push_back(words[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
