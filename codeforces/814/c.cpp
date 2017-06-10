#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1505;

char s[N];

int main () {
    int n;
    scanf(" %d %s", &n, s);
    
    int q;
    scanf(" %d", &q);
    while (q--) {
        int mi;
        char ci;
        scanf(" %d %c", &mi, &ci);

        int l = 0;
        int cont = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ci) {
                cont++;
                while (cont > mi) {
                    if (s[l] != ci) cont--;
                    l++;
                }
            }

            ans = max(ans, i - l + 1);
        }

        printf("%d\n", ans);
    }
}

