#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, m;
int p[N];
set<int> c1, c2, c3;

void put(int i, int a) {
    if (a == 1) c1.insert(p[i]);
    else if (a == 2) c2.insert(p[i]);
    else c3.insert(p[i]);
}

void del(int val) {
    if (c1.begin() != c1.end() && c1.find(val) != c1.end()) c1.erase(val);
    if (c2.begin() != c2.end() && c2.find(val) != c2.end()) c2.erase(val);
    if (c3.begin() != c3.end() && c3.find(val) != c3.end()) c3.erase(val);
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &p[i]);
    }

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            int a;
            scanf(" %d", &a);
            put(i, a);
        }
    }

    scanf(" %d", &m);
    while (m--) {
        int c;
        scanf(" %d", &c);
        int ans = -1;
        if (c == 1) {
            if (c1.begin() == c1.end()) { 
                printf("-1 ");
            } else {
                ans = *c1.begin();
                printf("%d ", ans);
            }
        } else if (c == 2) {
            if (c2.begin() == c2.end()) { 
                printf("-1 ");
            } else {
                ans = *c2.begin();
                printf("%d ", ans);
            }
        } else {
            if (c3.begin() == c3.end()) { 
                printf("-1 ");
            } else {
                ans = *c3.begin();
                printf("%d ", ans);
            }
        }

        del(ans);
    }
    printf("\n");
}

