#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 55;

int n, l;
int k[N], s[N];

int main () {
    scanf(" %d %d", &n, &l);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &k[i]);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &s[i]);
    sort(k, k + n);
    sort(s, s + n);
    for (int i = 0; i < l; i++) {
        bool equal = true;
        for (int j = 0; j < n; j++) 
            if (k[j] != s[j])
                equal = false;
        if (equal) {
            printf("YES\n");
            return 0;
        }
        for (int j = 0; j < n; j++) {
            s[j]--;
            if (s[j] < 0) s[j] = l - 1;
        }
        sort(s, s + n);
    }
    printf("NO\n");
}

