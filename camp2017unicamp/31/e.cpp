#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2000005;

int k;
int z[MAX], zb[MAX];
char t[MAX], p[MAX], s[MAX], sb[MAX];
vector<int> ans;

int main() {
    scanf(" %s %s %d", t, p, &k);
    int len_p = strlen(p), len_t = strlen(t);
    for (int i = 0; i < len_p; i++) 
        s[i] = p[i], sb[i] = p[len_p - i - 1];
    s[len_p] = sb[len_p] = '#';
    int len_s = len_p + len_t + 1;
    for (int i = len_p + 1; i < len_s; i++) {
        s[i] = t[i - len_p - 1];
        sb[i] = t[len_t - (i - len_p - 1) - 1];
    }
    int l = 0, r = 0;
    for (int i = 1; i < len_s; i++) {
        if (i <= r) 
            z[i] = min(z[i - l], r - i + 1);
        while (z[i] + i < len_s && s[z[i] + i] == s[z[i]])
            z[i]++;
        if (r < i + z[i] - 1) 
            l = i, r = i + z[i] - 1;
    }
    l = r = 0;
    for (int i = 1; i < len_s; i++) {
        if (i <= r) 
            zb[i] = min(zb[i - l], r - i + 1);
        while (zb[i] + i < len_s && sb[zb[i] + i] == sb[zb[i]])
            zb[i]++;
        if (r < i + zb[i] - 1) 
            l = i, r = i + zb[i] - 1;
    }
    
    for (int i = len_p + 1; i < len_s; i++) {
        int j = (len_s - (i - (len_p + 1)) - 1) - len_p + 1;
        //printf("i %d j %d z[i] %d zb[j] %d len_p %d\n", i, j, z[i], zb[j], len_p);
        if (j > len_p && len_p - (z[i] + zb[j]) <= k)
            ans.pb(i - len_p);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) 
        printf("%d ", ans[i]);
    printf("\n");
}


