//本题有两个队列：每个团队有一个队列，而团队整体又形成一个队列。例如，有3个团
//队1，2，3，队员集合分别为{101，102，103，104}、{201，202}和{301，302，303}，当前
//长队为{301，303，103，101，102，201}，则3个团队的队列分别为{103，101，102}、
//{201}和{301，303}，团队整体的队列为{3，1，2}。

#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

const int maxt = 1000 + 10;

int main() {
    int t, caseNum = 0;
    while (scanf("%d", &t) == 1 && t) {
        printf("Scenario #%d\n", ++caseNum);

        // 记录所有人的团队编号
        map<int, int> team;  // team[x]表示编号为x的人所在的团队编号
        for (int i = 0; i < t; i++) {
            int n, x;
            scanf("%d", &n);
            while (n--) {
                scanf("%d", &x);
                team[x] = i;
            }
        }

        // 模拟
        queue<int> q, q2[maxt];  // q是团队的队列，而q2[i]是团队i成员的队列
        while (1) {
            int x;
            string op;
            cin >> op;
            if (op[0] == 'S') {
                break;
            } else if (op[0] == 'D') {
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if (q2[t].empty()) {
                    q.pop();
                }
            } else if (op[0] == 'E') {
                cin >> x;
                int t = team[x];
                if (q2[t].empty()) {
                    q.push(t);  // 团队t进入队列
                }
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}