#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 55;

int n, k;
int v[N];
char s[5];

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) 
        v[i] = i;
    for (int i = 0; i < n - k + 1; i++) {
        scanf(" %s", s);
        if (s[0] == 'N') 
            v[i + k - 1] = v[i]; 
    }

    for (int i = 0; i < n; i++) {
        char ans[4];
        int p = 0;
        if (v[i] >= 26) {
            ans[p++] = 'A';
            v[i] -= 26;
            ans[p++] = 'a' + v[i];
        } else {
            ans[p++] = 'A' + v[i];
        }
        ans[p] = 0;
        printf("%s ", ans);
    } 
    printf("\n");
}

