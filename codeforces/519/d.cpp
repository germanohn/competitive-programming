#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int v[30], acc[N];
char s[N];
map<ll, int> mp[30];

int main () {
    for (int i = 0; i < 26; i++) 
        scanf(" %d", &v[i]);
    scanf(" %s", s);

    ll sum = 0, ans = 0;
    for (int i = 0; s[i] != 0; i++) {
        char c = s[i] - 'a';
        ans += mp[c][sum];
        sum += v[c];
        mp[c][sum]++;
    }

    printf("%lld\n", ans);
}

