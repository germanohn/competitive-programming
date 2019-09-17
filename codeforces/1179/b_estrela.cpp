#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);

    int l = 0; 
    int r = n * m - 1;
    for (int i = 0; i < n * m; i++) {
        int row, col, pos;
        if (i % 2 == 0) {
            pos = l;
            l++;
        } else {
            pos = r;
            r--;
        }

        row = pos / m + 1;
        col = pos % m + 1;

        printf("%d %d\n", row, col);
    }
}

