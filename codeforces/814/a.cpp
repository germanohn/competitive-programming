#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int a[105], b[105];

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }

    for (int i = 0; i < k; i++) {
        scanf(" %d", &b[i]);
    }

    if (k == 1) {
        bool ok = false;
        int pre;
        if (!a[0]) pre = b[0];
        else pre = a[0];
        for (int i = 1; !ok && i < n; i++) {
            if (a[i]) {
                if (a[i] < pre)
                    ok = true;
                pre = a[i];
            } else {
                if (b[0] < pre)
                    ok = true;
                pre = b[0];
            }
        }

        if (ok) printf("Yes\n");
        else printf("No\n");
    } else {
        printf("Yes\n");
    }
}

