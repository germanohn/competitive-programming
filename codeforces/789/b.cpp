#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll b, q, l, m;
set<ll> s;

int main () {
    scanf(" %lld %lld %lld %lld", &b, &q, &l, &m);
    for (int i = 0; i < m; i++) {
        int a;
        scanf(" %d", &a);
        s.insert(a);
    }

    if (abs(b) > l) {
        printf("0\n");
    } else {
        if (q == 0) {
            int ans = 0;
            if (s.find(b) == s.end())
                ans++;
            if (l < 0 || s.find(0) != s.end()) 
                printf("%d\n", ans);
            else
                printf("inf\n");
        } else if (q == -1) {
            if ((s.find(b) == s.end() && abs(b) <= l) || (s.find(b * q) == s.end() && abs(b * q) <= l))
                printf("inf\n");
            else 
                printf("0\n");
        } else if (q == 1) {
            if (s.find(b) == s.end()) 
                printf("inf\n");
            else
                printf("0\n");
        } else if (b == 0) {
            if (s.find(b) == s.end())
                printf("inf\n");
            else 
                printf("0\n");
        } else {
            int ans = 0;
            while (abs(b) <= l) {
                if (s.find(b) == s.end()) 
                    ans++;
                b *= q;
            }
            printf("%d\n", ans);
        }
    }
}

