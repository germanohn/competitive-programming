#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1123456;

int n, p, cost, k = 0;
int d[MAX];
char s1[25], s2[25], aux[25], aux2[25], str[25];
map<string, int> m;
vector<pii> adj[MAX];

void dijkstra () {
    priority_queue<pii> pq;
    d[1] = 1;
    pq.push (pii (0, 1));
    while (!pq.empty ()) {
        int u = pq.top ().ss;
        pq.pop ();
        //if (u == 1) 
          //  printf ("u == 1\n");
        for (int i = 0; i < adj[u].size (); i++) {
            pii v = adj[u][i];
            if (d[u] + v.ss < d[v.ff]) {
                d[v.ff] = d[u] + v.ss;
           //     printf ("d[v.ff] %d\n", d[v.ff]);
                pq.push (pii (-d[v.ff], v.ff));
            }
        }
    }
}

/*
void permut (int i, char* s) {
     if (s1[i] == 0) {
         strcpy (aux, s);
         for (int j = 0; s2[j] != 0; j++) {
             if (s2[j] == '-')
                 aux[j] = '-';
             else if (s2[j] == '+')
                 aux[j] = '+';
         } 
         //printf("aux %s\n", aux);
         //printf ("s %s\n", s);
         if (m[s] == 0) 
             m[s] = ++k;
         if (m[aux] == 0)
             m[aux] = ++k;
         //if (strcmp (str, s) == 0) 
          //  printf ("tudo mais m[s] %d m[aux] %d\n", m[s], m[aux]);
         adj[m[s]].pb (pii (m[aux], cost));
         adj[m[aux]].pb (pii (m[s], cost));
         return;
     }    
     else if ( s1[i] == '0' ) {
         s[i] = '+';
         permut (i+1, s);
         s[i] = '-';
         permut (i+1, s);
     } else {
         s[i] = s1[i];
         permut (i+1, s);
     }
}
*/

int main () {
    int test = 1;
    while (scanf ("%d %d", &n, &p) && n != 0 && p != 0) {
        for ( int i = 0; i < k; i++ )
            adj[i].clear();
        k = 1;
        m.clear();  
        for (int i = 0; i < n; i++) 
            aux[i] = '+';
        strcpy (str, aux);
        m[aux] = 1;
        for (int i = 0; i < p; i++) {
            scanf ("%d %s %s", &cost, s1, s2);
            strcpy(aux2,s1);
            permut (0, aux2);
            //printf ("s1 %s aux %s\n", s1, aux);
        }
        //printf ("k %d\n", k);
        for (int i = 0; i <= k; i++) 
            d[i] = MAX;
        //printf ("tam %d\n", adj[1].size ());
        dijkstra ();
        for (int i = 0; i < n; i++)
            aux[i] = '-'; 
        printf ("Product %d\n", test++);
        if (d[m[aux]] == MAX) 
            printf ("Bugs cannot be fixed.\n");
        else 
            printf ("Fastest sequence takes %d seconds.\n", d[m[aux]]);
    }
}

