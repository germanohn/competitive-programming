#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define eps 1e-9
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int p[20], mark[500];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", p + i);

    for (int i = 1; i <= 100; i++) {
        bool cagou = false;
        for (int j = 0; j <= i; j++) {
            double c = ((double) j) / ((double) i);
            c *= 100;
            int f = (int) round(c);
            mark[f] = i;
        }
        for (int j = 0; j < n; j++)
            if (mark[p[j]] < i) cagou = true;
        if (!cagou) {
            printf("%d\n", i);
            return 0;
        }
    }
}

