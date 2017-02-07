#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1123;

int n;
ll a[N];

int main () {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%lld", a+i);
    sort(a, a+n);
    ll acc = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > acc) {
            ans++;
            acc += a[i];
        }
    }
    printf("%d\n", ans);
}

