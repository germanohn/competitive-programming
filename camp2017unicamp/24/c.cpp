#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int d, r, t;
    scanf(" %d %d %d", &d, &r, &t);
    int ir, it, yr, yt;
    ir = 0, it = 0, yr = 4, yt = 3;
    for (int i = 1; i < d; i++)
        ir += yr++;
    while (ir + it < r + t)
        ir += yr++, it += yt++;
    printf("%d\n", r - ir);
}

