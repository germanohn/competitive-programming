#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MAX = 10005;

int t, ini, fim, k;
int d[MAX], pri[MAX];
bool p[MAX];
char str[10];
vector<int> adj[MAX];
queue<int> q;

void crivo () {
    for (int i = 2; i*i < MAX; i++) {
        if (!p[i]) {
            for (int j = i*i; j < MAX; j+=i) {
                p[j] = true;
            }
        }
    }
    for (int i = 1000; i < MAX; i++) {
        if (!p[i]) pri[k++] = i;
    }
}

void bfs () {
    while (!q.empty ()) {
        int x = q.front ();
        q.pop ();
        for (int i = 0; i < adj[x].size (); i++) {
            int nx = adj[x][i];
            if (d[nx] > d[x] + 1) {
                d[nx] = d[x] +1;
                q.push (nx);
            }
        }
    }
}

void ppath () {
    for (int i = 0; i < k; i++) {
        int num;
        sprintf (str, "%d", pri[i]);
        char aux[10];
        for (int j = 0; j < 4; j++) {
            strcpy (aux, str);
            for (int l = 0; l <= 9; l++) {
                if (str[j] != l+'0' && (l != j)) {
                    aux[j] = l+'0';
                    num = atoi (aux);
                    if (!p[num]) {
                        adj[pri[i]].pb (num);
                        adj[num].pb (pri[i]);
                    }
                }
            }
        }
    }
}

int main () {
    scanf ("%d", &t);
    crivo ();
    ppath ();
    while(t--) {
        for (int i = 1000; i < MAX; i++)
            d[i] = INT_MAX;
        scanf ("%d %d", &ini, &fim);
        q.push (ini);
        d[ini] = 0;
        bfs ();
        if (d[fim] == INT_MAX) printf ("Impossible\n");
        else printf ("%d\n", d[fim]);
    }
}
