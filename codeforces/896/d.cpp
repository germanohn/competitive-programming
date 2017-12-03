#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1e3 + 5;

int n, m, c;

int main() {
    scanf(" %d %d %d", &n, &m, &c);
    bool menor = false;
    int _min = N;
    int l = 1, r = n, mid = 2;
    int q[3] = {0, 0, 0};
    for (int i = 0; i < m; i++) {
        int pi;
        scanf(" %d", &pi);
        if (pi == 1) {
            printf("%d\n", l++);
            q[0]++;
        } else if (q[1] == n - 1 && pi == 2) {
            printf("1\n");
            q[1]++;
        } else if (pi > 1 && pi < c) {
            printf("%d\n", mid++);
            q[1]++;
        } else {
            printf("%d\n", r--);
            q[2]++;
        } 
        if (q[0] + q[1] + q[2] == n) 
            break;
        fflush(stdout);
    }
}

