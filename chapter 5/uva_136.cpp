#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int coeff[3] = {2, 3, 5};
int main() {
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    set<long long> s;
    pq.push(1);
    s.insert(1);
    
    for (int i = 1;; i++) {
        long long x = pq.top();
        pq.pop();
        if (i == 1500) {
            cout << "The 1500'th ugly number is " << x << "." << endl;
            break;
        }
        for (int j = 0; j < sizeof(coeff) / sizeof(coeff[0]); j++) {
            long long newValue = x * coeff[j];
            if (!s.count(newValue)) {
                s.insert(newValue);
                pq.push(newValue);
            }
        }
    }
    return 0;
}