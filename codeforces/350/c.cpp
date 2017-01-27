#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
pii pto[MAX];

bool cmp(pii a, pii b) {
    /*
    if (abs(a.ff) != abs(b.ff)) return abs(a.ff) < abs(b.ff);
    return abs(a.ss) < abs(b.ss);*/
    return abs(a.ff) + abs(a.ss) < abs(b.ff) + abs(b.ss);
}

int main () {
    scanf(" %d", &n);
    int k = 6 * n;
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &pto[i].ff, &pto[i].ss);
        if (!pto[i].ff || !pto[i].ss) k -= 2;
    }
    sort(pto, pto + n, cmp);
    printf("%d\n", k); 
    for (int i = 0; i < n; i++) {
        if (pto[i].ff < 0) 
            printf("1 %d L\n", abs(pto[i].ff));
        else if (pto[i].ff > 0) 
            printf("1 %d R\n", pto[i].ff);
        if (pto[i].ss < 0) 
            printf("1 %d D\n", abs(pto[i].ss));
        else if (pto[i].ss > 0)
            printf("1 %d U\n", pto[i].ss);
        printf("2\n");
        if (pto[i].ss < 0) 
            printf("1 %d U\n", abs(pto[i].ss));
        else if (pto[i].ss > 0)
            printf("1 %d D\n", pto[i].ss);
        if (pto[i].ff < 0) 
            printf("1 %d R\n", abs(pto[i].ff));
        else if (pto[i].ff > 0)
            printf("1 %d L\n", pto[i].ff);
        printf("3\n");
    }
}

