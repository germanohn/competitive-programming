#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 112345;
int f[N], n, l;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d",&x);
        f[x]++;
    }
    for(int i = 0; i < N; i++) {
        if(f[i] % l) {
            puts("ARGH!!1");
            return 0;
        }
    }
    puts("OK");
}

