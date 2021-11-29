#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct cmp {  // a的优先级比b小时返回true
    bool operator()(const int a, const int b) const { return a % 10 < b % 10; }
};

int main() {
    priority_queue<int> pq1;  //越大的整数优先级越大
    priority_queue<int, vector<int>, cmp> pq;
    priority_queue<int, vector<int>, greater<int> > pq2;  // 越小的整数优先级越大
}
