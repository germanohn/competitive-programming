#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n;
int pre[MAX], z[2 * MAX];
char s[2 * MAX];

int main() {
    scanf(" %d", &n);
    scanf(" %d", &pre[0]);
    for (int i = 1; i < n; i++) {
        scanf(" %d", &pre[i]);
        if (!pre[i]) {
            s[i] = s[pre[i - 1]] + 1;
        } else {
            s[i] = s[pre[i] - 1];
        }
    }
    s[n] = 0;

    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) 
            z[i] = min(z[i - l], r - i + 1);
        while (z[i] + i < n && s[z[i]] == s[z[i] + i])
            z[i]++;
        if (r < z[i] + i - 1)
            l = i, r = z[i] + i - 1;
    }
    
    for (int i = 0; i < n; i++) 
        printf("%d ", z[i]);
    printf("\n");
}

