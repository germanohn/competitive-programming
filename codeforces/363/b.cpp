#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n, k;
int acc[MAX];

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &acc[i + 1]);
        acc[i + 1] += acc[i];
    }
    int ans = INT_MAX, pos = -1;
    for (int i = 0; i <= n - k; i++) {
        if (ans > acc[i + k] - acc[i])
            ans = acc[i + k] - acc[i], pos = i + 1;
    }
    printf("%d\n", pos);
}

