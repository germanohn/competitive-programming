#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int v[105];

int main () {
    scanf(" %d", &n);
    int acc = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        acc += v[i];
    }
    sort(v, v + n);
    int x = 0, cont = 0;
    for (int i = n - 1; i >= 0; i--) {
        x += v[i], cont++;
        if (x > acc - x) 
            break;
    }
    printf("%d\n", cont);
}

