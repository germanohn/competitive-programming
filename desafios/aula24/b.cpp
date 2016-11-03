#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1005;

pii v[MAX];

int cross(int i) {
    return ((v[i].ff - v[i - 1].ff) * (v[i + 1].ss - v[i].ss)) - ((v[i].ss - v[i - 1].ss) * (v[i + 1].ff - v[i].ff));
}

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i <= n; i++) {
        scanf(" %d %d", &v[i].ff, &v[i].ss);
    }

    int dangerous = 0;
    for (int i = 1; i < n; i++) {
        if (cross(i) > 0) dangerous++;
    }

    printf("%d\n", dangerous); 
}
