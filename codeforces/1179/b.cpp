#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n, m;

void traverse(int r1, int r2) {
    if (r1 > r2) 
        return;

    if (r1 == r2) {
        int l = 1, r = m;
        for (int i = 0; i < m; i++) {
            if (i % 2 == 0) {
                printf("%d %d\n", r1, l);
                l++;
            } else {    
                printf("%d %d\n", r1, r);
                r--;
            }
        }
        return;
    }

    for (int i = 0; i < m; i++) {
        printf("%d %d\n", r1, i + 1);
        printf("%d %d\n", r2, m - i);
    }
    traverse(r1 + 1, r2 - 1);
}

int main() {
    scanf(" %d %d", &n, &m);
    traverse(1, n);
}

