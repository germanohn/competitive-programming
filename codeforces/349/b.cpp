#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int v;
int cost[10];
char ans[MAX];

int main() {
    scanf(" %d", &v);
    for (int i = 0; i < 9; i++) {
        scanf(" %d", &cost[i]);
    }
    int len, ind;
    len = -1;
    for (int i = 0; i < 9; i++) {
        if (len < v / cost[i]) {
            len = v / cost[i];
            ind = i;
        }
    }
    for (int i = 0; i < len; i++)
        ans[i] = ind + '1';
    ans[len] = 0;
    int remain = v - (cost[ind] * len);
    int best = 8;
    for (int i = 0; i < len; i++) {
        remain += cost[ind];
        while (cost[best] > remain)
            best--;
        if (cost[best] <= remain) {
            ans[i] = best + '1';
            remain -= cost[best];
        } else { 
            remain -= cost[ind];
        }
    }
    if (len == 0) printf("-1\n");
    else 
        printf("%s\n", ans);
}
