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

struct relacao {
	vector<int> pos, neg;
	int cost, pat;
}

int n, p, cost;
int d[MAX];
char s1[25], s2[25], aux[25], aux2[25], str[25];
vector<pii> adj[MAX];
vector<int> pos[MAX], neg[MAX];
set<int> q;

void dijkstra () {
    priority_queue<pii> pq;
    d[0] = 1;
    pq.push (pii (0, 0));
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

int convert (string s) {
	int tam = s.length (), k = 0, val = 0;
	for (int i = tam-1; i >= 0; i--) {
		if (s[i] == '-') 
			val += (1 << k);
		k++;
	}
	return val;
}

void permut (int i, char* s) {
     if (s1[i] == 0) {
         strcpy (aux, s);
         for (int j = 0; s2[j] != 0; j++) {
             if (s2[j] == '-')
                 aux[j] = '-';
             else if (s2[j] == '+')
                 aux[j] = '+';
         } 
		 int a = convert (aux); 
		 int b = convert (s);
		 //printf ("aux %s a %d s2 %s b %d\n", aux, a, s2, b);
		 d[a] = d[b] = MAX;
		 q.insert (a), q.insert (b);
         adj[a].pb (pii (b, cost));
         adj[b].pb (pii (a, cost));
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

int main () {
    int test = 1;
    while (scanf ("%d %d", &n, &p) && n != 0 && p != 0) {
        for ( int i = 0; i < q.size (); i++ )
            adj[i].clear();
        for (int i = 0; i < p; i++) {
            scanf ("%d %s %s", &rel[i].cost, s1, s2);
			int tam = s1.length (), k = 0;
			for (int j = tam-1; j >= 0; j--) {
				if (s1[j] == '+') {
					rel[i].pos.pb (k);
				} else if (s1[j] == '-') {
					rel[i].neg.pb (k);
				}
				k++;
			}
			rel[i].s = s2;
        }
		vp.pb (0);
		for (int i = 0; i < vp.size (); i++) {
			for (int i = 0; i < p; i++) {}
		}
        dijkstra ();
        printf ("Product %d\n", test++);
		int end = (1 << n) - 1;
        if (d[end] == MAX) 
            printf ("Bugs cannot be fixed.\n");
        else 
            printf ("Fastest sequence takes %d seconds.\n", d[end]);
		printf ("\n");
    }
}

