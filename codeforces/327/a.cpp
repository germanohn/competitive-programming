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

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }
    int l, r, p, ans, aux;
    aux = ans = p = 0;
    l = r = -1;
    for (int i = 0; i < n; i++) {
        if (!v[i]) aux++;
        else aux--;
        if (aux < 0) 
            p = i + 1, aux = 0;
        else if (aux > ans) 
            ans = aux, l = p, r = i;
    }
    if (l != -1) 
        for (int i = l; i <= r; i++) {
            if (!v[i]) v[i] = 1;
            else v[i] = 0;
        }
    else {
        printf("%d\n", n - 1);
        return 0;
    }
    int cont = 0;
    for (int i = 0; i < n; i++) 
        if (v[i]) cont++;
    printf("%d\n", cont);
}
