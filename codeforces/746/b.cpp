#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
char s[2005];
char ans[2005];

int main () {
    scanf(" %d", &n);
    scanf(" %s", s);
    int p = 0;
    if (n % 2 == 0) {
        int mid = n/2 - 1;
        int l, r;
        l = mid, r = mid + 1;
        for (int i = 0; i < n; i += 2) {
            ans[l--] = s[p++];
            ans[r++] = s[p++];
        }
    } else {
        int mid = n/2;
        int l, r;
        l = mid - 1, r = mid + 1;
        ans[mid] = s[p++];
        for (int i = 0; i < n - 1; i += 2) {
            ans[l--] = s[p++];
            ans[r++] = s[p++];
        }
    }
    printf("%s\n", ans);
}

