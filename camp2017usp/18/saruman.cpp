#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e4 + 5;

int t;
int n, k;
char s[N];

int main () {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d %s", &n, &k, s);

        if (n == 1) {
            printf("1\n");
        } else {
            int cont = 0, ans = 0;
            bool ok = false;
            for (int i = 0; i < n; i++) {
                cont++;
                if (cont >= k) ok = true;

                if (s[i] != s[i + 1]) {
                    ans += (cont + k - 1) / k;
                    cont = 0;
                }
            }

            if (ok) printf("%d\n", ans);
            else printf("-1\n");
        }
    }
}
