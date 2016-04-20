#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1123456;
const int inf = 1000000000;

struct relacao {
	char s1[25], s2[25];
	int cost;
};

int n, p;
int d[MAX];
bool vis[MAX];
relacao rel[MAX];

bool fit (int val, char* s) {
	int k = 0;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '-') {
			if (!(val & (1 << k)))
				return false;
		} else if (s[i] == '+') {
			if (val & (1 << k))
				return false;
		}
		k++;
	}
	return true;
}
	
int convert (int val, char* s) {
	int k = 0;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '-') {
			if (!(val & (1 << k)))
				val += (1 << k);		
		} else if (s[i] == '+') {
			if (val & (1 << k))
				val -= (1 << k);
		}
        k++;
	}
	return val;
}

void dijkstra () {
    priority_queue<pii> pq;
    d[0] = 0;
	pq.push (pii (0, 0));
    while (!pq.empty ()) {
        int u = pq.top ().ss;
        pq.pop ();
		// pra cada cara que fiz vou ver em quais patches ele se encaixa 
		// se encaixar eu relaxo a aresta e coloco na pq
        if (vis[u])
            continue;
        vis[u] = true;
        if (u == (1 << n)-1) 
            break;
		for (int i = 0; i < p; i++) {
      //      printf ("i %d\n", i);
			if (fit (u, rel[i].s1)) {
        //        printf ("u %d s %s\n", u, s.c_str ());
			// entao agora preciso usar o patch 		
				int v = convert (u, rel[i].s2);
          //      printf ("v %d s %s\n", v, s.c_str ());
				if (d[u] + rel[i].cost < d[v]) {
            //        printf ("dis v %d\n", v);
					d[v] = d[u] + rel[i].cost;
					pq.push (pii (-d[v], v));
				}
			}
		}
    }
}

int main () {
	int test = 1;
    while (scanf ("%d %d", &n, &p) && n != 0 && p != 0) {
		for (int i = 0; i < (1 << n); i++)
			d[i] = inf, vis[i] = false;
        for (int i = 0; i < p; i++) 
            scanf ("%d %s %s", &rel[i].cost, rel[i].s1, rel[i].s2);	
		dijkstra ();
		printf ("Product %d\n", test++);
		int end = (1 << n) - 1;
		if (d[end] == inf)
			printf ("Bugs cannot be fixed.\n");
		else  
			printf ("Fastest sequence takes %d seconds.\n", d[end]);
        printf ("\n");
    }
}
