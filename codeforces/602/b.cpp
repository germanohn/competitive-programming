#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int v[100005];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    int l, a, ans;
    l = 0, a = -1, ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] - v[i - 1] != 0) {
            if (a != -1 && v[i] - v[i - 1] == v[a] - v[a - 1]) 
                    l = a;
            a = i;
        }
        ans = max(ans, i - l + 1);
    }
    printf("%d\n", ans);
}

