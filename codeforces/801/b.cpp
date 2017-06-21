#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char x[105], y[105], z[105];

int main () {
    scanf(" %s %s", x, y);

    for (int i = 0; x[i] != 0; i++) {
        if (x[i] < y[i]) {
            printf("-1\n");
            return 0;
        } else if (x[i] == y[i]) {
            z[i] = x[i];
        } else {
            z[i] = y[i];
        }
    }

    printf("%s\n", z);
}

