#include <bits/stdc++.h>
#define MAX 105
#define pb push_back

using namespace std;

int a, v, cont = 1, ini, fim;
vector<int> adj[MAX];

int main () {
    while (scanf ("%d %d", &a, &v) && a != 0 && v != 0) {
        for (int i = 1; i <= a; i++)
            adj[i].clear ();
        for (int i = 0; i < v; i++) {
            scanf ("%d %d", &ini, &fim);
            adj[ini].pb (fim);
            adj[fim].pb (ini);
        }
        int maior = 0; 
        for (int i = 1; i <= a; i++) {
            if (adj[i].size () > maior)
                maior = adj[i].size ();
        }
        printf ("Teste %d\n", cont++);
        for (int i = 1; i <= a; i++) {
            if (adj[i].size () == maior) 
                printf ("%d ", i);
        }
        printf ("\n\n");
    }
}
