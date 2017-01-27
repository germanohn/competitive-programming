#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, k, a, b;
char ans[MAX];

int main () {
    scanf(" %d %d %d %d", &n, &k, &a, &b);
    int p = 0;
    while (a + b > 0) {
        if (a < b) {
            int q_b = min(b - a, k);
            for (int i = p; i < p + q_b; i++) 
                ans[i] = 'B';
            p += q_b;
            b -= q_b;
            if (a == 0 && b != 0) {
                printf("NO\n");
                return 0;
            } else if (a != b) {
                ans[p++] = 'G';
                a--;
            }
        } else if (a > b) {
            int q_g = min(a - b, k);
            for (int i = p; i < p + q_g; i++) 
                ans[i] = 'G';
            p += q_g;
            a -= q_g;
            if (b == 0 && a != 0) {
                printf("NO\n");
                return 0;
            } else if (a != b) {
                ans[p++] = 'B';
                b--;
            }
        } else {
            if (ans[p - 1] == 'G') {
                ans[p++] = 'B', b--;
                ans[p++] = 'G', a--;
            } else {
                ans[p++] = 'G', a--;
                ans[p++] = 'B', b--;
            }
        }
    }
    for (int i = 0; i < n; i++) 
        printf("%c", ans[i]);
    printf("\n");
}

