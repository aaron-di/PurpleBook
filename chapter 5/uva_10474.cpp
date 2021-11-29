#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, q, x, a[10000];
    int caseNum = 0;
    while (scanf("%d %d", &n, &q) == 2 && n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        printf("CASE# %d:\n", ++caseNum);
        while (q--) {
            scanf("%d", &x);
            int pos = lower_bound(a, a + n, x) - a;  // lower_bound返回的是范围内第一个大于等于x的值的地址
            if (a[pos] == x)
            {
                printf("%d found at %d\n", x, pos+1);
            } else {
                printf("%d not found\n", x);
            }
        }
    }
}