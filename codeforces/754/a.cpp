#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

int n;
int v[MAX];

int main () {
    scanf(" %d", &n);
    int acc = 0;
    bool no_zero = false;
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        if (v[i]) no_zero = true;
        acc += v[i];
    }
    if (!no_zero) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    if (acc != 0) {
        printf("1\n1 %d\n", n);
    } else {
        for (int i = 0; i < n; i++) {
            if (v[i]) { 
                printf("2\n1 %d\n%d %d\n", i + 1, i + 2, n); 
                break;
            }
        }
    }
}

