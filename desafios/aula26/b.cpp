#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e9;

int pot[50], v[100005];
map<int, int> freq;

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        freq[v[i]]++;
    }

    int aux = 2, qtd = 0;
    for (qtd = 0; aux <= MAX; qtd++) 
        pot[qtd] = aux, aux *= 2;

    pot[qtd++] = aux;

    ll ans = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < qtd; j++) { 
            int goal = pot[j] - v[i];

            if (goal == v[i]) ans += (ll) (freq[goal] - 1);
            else ans += (ll) freq[goal];      
        }

    printf("%lld\n", ans/2);
}
