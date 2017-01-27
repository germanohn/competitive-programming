#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 500005;

int n;
int v[MAX];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    sort(v, v + n);
    int p = n / 2, cont = n;
    for (int i = 0; i < n / 2; i++) {
        for (; p < n; p++) {
            if (2 * v[i] <= v[p]) {
                cont--, p++;
                break;
            }
        } 
    }
    printf("%d\n", cont);
}

