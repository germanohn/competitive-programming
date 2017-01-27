#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int v[4];

int main () {
    for (int i = 0; i < 3; i++) 
        scanf(" %d", &v[i]);
    sort(v, v + 3);
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int aux = 0;
        if (v[0] - i >= 0) {
            aux += i;
            for (int j = 0; j < 3; j++) 
                aux += ((v[j] - i) / 3);
            ans = max(ans, aux);
        }
    }
    printf("%d\n", ans);
}

