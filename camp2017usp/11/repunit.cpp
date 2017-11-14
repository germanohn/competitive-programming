#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, a, b;

int main () {
    scanf(" %lld %lld %lld", &n, &a, &b);
    a--, b--;
    ll cn = 2 * n - 2;
    a = cn - a;
    b = cn - b;


    if (b <= cn / 2) {
        int carry = ((b / 2) - 10) / 9;
        
        int p = 0;
        for (int i = b; i <= a; i++) {
            int cur;
            if (i <= cn / 2) {
                cur = i + 1;
            } else {
                cur = cn - i + 1;
            }
            
            int let = (cur + carry) % 10;
            ans[p++] = let;
            carry = (cur + carry - let) / 10;
        }    
    } else {
        int carry = ((cn / 2) - 10) / 9;        
        
        for (int i = cn / 2; ; i++) {
            
        }
    }
}

