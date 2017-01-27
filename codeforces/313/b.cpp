#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, m;
char s[MAX];
int acc[MAX];

int main () {
    scanf(" %s", s);
    n = strlen(s);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) acc[i + 1]++;
        acc[i + 1] += acc[i];
    }
    scanf(" %d", &m);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        printf("%d\n", acc[r - 1] - acc[l - 1]);
    }
}

