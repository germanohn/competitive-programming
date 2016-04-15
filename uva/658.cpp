#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 112345678;

int n, p, cost, k;
int d[MAX];
char s1[25], s2[25], aux[25];
map<string, int> m;
vector<pii> adj[MAX];

void dijkstra () {
    priority_queue<pii> pq;
    d[0] = 0;
    pq.push (pii (0, 0));
    while (!pq.empty ()) {
        int u = pq.top ().ss;
        pq.pop ();
        for (int i = 0; i < adj[u].size (); i++) {
            pii v = adj[u][i];
            if (d[u] + v.ss < d[v.ff]) {
                d[v.ff] = d[u] + v.ss;
                pq.push (pii (-d[v.ff], v.ss));
            }
        }
    }
}

 void permut (int i, char* s) {
     if (s[i] == 0) {
         strcpy (aux, s);
         for (int j = 0; s2[j] != 0; j++) {
             if (s2[j] == '-')
                 aux[j] = '-';
             else if (s2[j] == '+')
                 aux[j] = '+';
         } 
         if (m[s] == 0) 
             m[s] = k++;
         if (m[aux] == 0)
             m[aux] = k++;
         adj[m[s]].pb (pii (m[aux], cost));
         adj[m[aux]].pb (pii (m[s], cost));
         return;
     }    
     if (s[i] == '0') {
         s[i] = '-';
         permut (i+1, s);
         s[i] = '+';
         permut (i+1, s);
     } else {
         permut (i+1, s);
     }
 }

int main () {
    int test = 1;
    while (scanf ("%d %d", &n, &p) && n != 0 && p != 0) {
        k = 1;
        for (int i = 0; i < n; i++) 
            aux[i] = '+';
        m[aux] = 0;
        for (int i = 0; i < p; i++) {
            scanf ("%d %s %s", &cost, s1, s2);
            permut (0, s1);
            //printf ("s1 %s aux %s\n", s1, aux);
        }
        printf ("oi\n");
        for (int i = 0; i < k; i++) 
            d[i] = MAX;
        dijkstra ();
        for (int i = 0; i < n; i++)
            aux[i] = '-'; 
        printf ("Product %d\n", test++);
        if (d[m[aux]] == 0) 
            printf ("Bugs cannot be fixed.\n");
        else 
            printf ("Fastest sequence takes %d seconds.\n", d[m[aux]]);
    }
}

