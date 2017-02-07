#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        int a;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a);
            ans ^= a;
        }
        if(!ans) puts("NIE");
        else puts("TAK");
    }

}

