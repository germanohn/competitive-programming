#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t1, t2;
    scanf("%d %d %d", &n, &t1, &t2);
    int ans = 0;
    int turn = -1;
    int a, b, last;
    a = t1, b = t2;
    while(ans < n) {
        if(a == b) {
            ans += 2;
            turn = 2;
            last = a;
            a += t1;
            b += t2;
        } else if(a < b) {
            ans++;
            turn = 0;
            last = a;
            a += t1;
        } else {
            ans++;
            turn = 1;
            last = b;
            b += t2;
        }
    }
    if(turn == 0) {
        last = b;
        ans++;
    } else if(turn == 1) {
        last = a;
        ans++;
    }
    printf("%d %d\n", ans, last);
    
}

