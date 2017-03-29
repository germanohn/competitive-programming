#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e3 + 5;

int n;
pii v[N];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &v[i].ff, &v[i].ss);
    }
    sort(v, v + n);

    int _min = 0;
    for (int i = 0; i < n; i++) {
        int a = min(v[i].ff, v[i].ss);
        int b = max(v[i].ff, v[i].ss);
        if (a >= _min)
            _min = a;
        else
            _min = b;
    }
    printf("%d\n", _min);
}

