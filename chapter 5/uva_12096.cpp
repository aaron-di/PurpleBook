#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

// 本题的集合并不是简单的整数集合或者字符串集合，而是集合的集合。为了方便起见，
// 此处为每个不同的集合分配一个唯一的ID，则每个集合都可以表示成所包含元素的ID集合，
// 这样就可以用STL的set<int>来表示了，而整个栈则是一个stack<int>。

typedef set<int> Set;
map<Set, int> IDcache;  // 把集合映射成ID
vector<Set> Setcache;   // 根据ID取集合，ID即vector的序号

//查找给定集合x的ID，如果找不到，分配一个新的ID
int getID(Set x) {
    if (IDcache.count(x)) {
        return IDcache[x];
    } else {
        Setcache.push_back(x);  // 添加新集合
        return IDcache[x] = Setcache.size() - 1;
        // 对任意集合s（类型是上面定义的Set），IDcache[s]就是它的ID，而Setcache[IDcache[s]] 就是s本身。
    }
}

int main() {
    stack<int> s;  //题目中的栈
    int caseNum;
    cin >> caseNum;
    for (int case_i = 0; case_i < caseNum; case_i++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            string op;
            cin >> op;
            if (op[0] == 'P') {
                s.push(getID(Set()));
            } else if (op[0] == 'D') {
                s.push(s.top());
            } else {
                Set x1 = Setcache[s.top()];
                s.pop();
                Set x2 = Setcache[s.top()];
                s.pop();
                Set x;
                if (op[0] == 'U') {
                    set_union(ALL(x1), ALL(x2), INS(x));
                }
                if (op[0] == 'I') {
                    set_intersection(ALL(x1), ALL(x2), INS(x));
                }
                if (op[0] == 'A') {
                    x = x2;
                    x.insert(getID(x1));
                }
                s.push(getID(x));
            }
            cout << Setcache[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}
