#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

int t[N], x[N], y[N];

int manhattan_distance(int a, int b) {
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

int main() {
    int n;
    scanf(" %d", &n);
    t[0] = x[0] = y[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf(" %d %d %d", &t[i], &x[i], &y[i]);
    }
    bool can = true;
    for (int i = 1; can && i <= n; i++) {
        int d_m = manhattan_distance(i - 1, i);
        int d_t = t[i] - t[i - 1];
        if (d_m > d_t || (d_t - d_m) % 2 != 0)
            can = false;
    }
    if (can) 
        printf("Yes\n");
    else 
        printf("No\n");
}

