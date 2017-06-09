#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, x;

int main() {
    scanf(" %d %d", &n, &x);

    /* Simula do começo para o final 
    n %= 6;

    if (!n) {
        printf("%d\n", x);
    } else {
        for (int i = 0; i < 3; i++) {
            int cur = i;
            for (int j = 1; j <= n; j++) {
                if (j % 2 == 1) {
                    if (cur == 1) cur = 0;
                    else if (cur == 0) cur = 1;
                } else {
                    if (cur == 1) cur = 2;
                    else if (cur == 2) cur = 1;
                }
            }
            if (cur == x) {
                printf("%d\n", i);
                break;
            }
        }
    }
    */

    /* Simula do final para o comeco */

    n %= 6;
    
    for (int i = n; i > 0; i--) {
        if (i % 2 == 0) {
            if (x == 1) x = 2;
            else if (x == 2) x = 1;
        } else {
            if (x == 0) x = 1;
            else if (x == 1) x = 0;
        }
    }
    printf("%d\n", x);
}
