#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1123456;
const int inf = 123456789;

struct relacao {
	char s1[25], s2[25];
	int cost;
};

int n, p;
int d[MAX];
relacao rel[MAX];

bool fit (int val, string s) {
	int tam = s.length (), k = 0;
	for (int i = tam-1; i >= 0; i--) {
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
	
int convert (int val, string s) {
	int tam = s.length (), k = 0;
	for (int i = tam-1; i >= 0; i--) {
		if (s[i] == '-') {
			if (!(val & (1 << k)))
				val += (1 << k);		
		} else if (s[i] == '+') {
			if (val & (1 << k))
				val -= (1 << k);
		}
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
		for (int i = 0; i < p; i++) {
			string s = rel[i].s1;
			if (fit (u, s)) {
			// entao agora preciso usar o patch 		
				s = rel[i].s2;
				int v = convert (u, s);
				if (d[u] + rel[i].cost < d[v]) {
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
			d[i] = inf;
        for (int i = 0; i < p; i++) 
            scanf ("%d %s %s", &rel[i].cost, rel[i].s1, rel[i].s2);	
		dijkstra ();
		printf ("Product %d\n", test++);
		int end = (1 << n) - 1;
		if (d[end] == inf)
			printf ("Bugs cannot be fixed.\n");
		else  
			printf ("Fastest sequence takes %d seconds.\n", d[end]);
    }
}
