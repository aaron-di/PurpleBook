#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;                  //总块数
vector<int> pile[100];  //每一个pile都是vector因为长度可能变化

//找到a的pile和height直接返回给调用者
void find_block(int a, int &p, int &h) {
    for (p = 0; p < n; p++) {
        for (h = 0; h < pile[p].size(); h++) {
            if (pile[p][h] == a) {
                return;
            }
        }
    }
}

//把第p堆高度为h的木块上方的所有木块移回原位
void clear_above(int p, int h) {
    for (int i = h + 1; i < pile[p].size(); i++) {
        int block = pile[p][i];
        pile[block].push_back(block);  //把木块b放回原位
    }
    pile[p].resize(h + 1);  // pile[p]应该只保留0~h个元素
}

//把第p堆高度为h及其上方的木块全部移到p2堆的顶部
void pile_onto(int p, int h, int p2) {
    for (int i = h; i < pile[p].size(); i++) {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);  // pile[p]只保留0~(h-1)个元素
}

void print() {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < pile[i].size(); j++) {
            printf(" %d", pile[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a, b;
    string s1, s2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        pile[i].push_back(i);
    }
    while (cin >> s1) {
        if (s1 == "quit") {
            break;
        }
        cin >> a >> s2 >> b;
        int pa, pb, ha, hb;
        find_block(a, pa, ha);
        find_block(b, pb, hb);
        if (pa == pb) {
            continue;
        }  //指令在同一堆非法
        if (s2 == "onto") {
            clear_above(pb, hb);
        }
        if (s1 == "move") {
            clear_above(pa, ha);
        }
        pile_onto(pa, ha, pb);
    }

    print();
    return 0;
}