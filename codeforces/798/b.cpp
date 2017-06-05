#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 55;

int n;
char s[N][2 * N];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %s", s[i]);
    int len = strlen(s[0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++) {
            s[i][j + len] = s[i][j];
        }
    }

    int ans = N * N;
    for (int l = 0; l < len; l++) {
        int mov = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            bool eq;
            for (int st = 0; st < len; st++) {
                int cont = 0;
                eq = true;
                for (int j = st; cont < len; j++) {
                    int cur = j - st + l;
                    if (s[i][j] != s[0][cur]) {
                        eq = false;
                        break;
                    }
                    cont++;
                }
                if (eq) {
                    mov += st;
                    break;
                }
            } 
            if (!eq) {
                ok = false;
                break;
            }
        }
        if (ok) ans = min(ans, mov);
    }

    if (ans == N * N) 
        printf("-1\n");
    else 
        printf("%d\n", ans);
}

