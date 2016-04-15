#include <bits/stdc++.h>
using namespace std;

int n, p;
pii<string, string> 

void dijkstra () {
    priority_queue pq;
    d[0] = 0;
    pq.push (pii (0, 0));
    while (!pq.empty ()) {
        int u = pq.top ().ss;
        pq.pop ();

    }
}

int num (char* str) {
    int tam = strlen (str);
    int x = 0, pot = 1;
    for (int i = tam-1; i >= 0; i--) {
        if (str[i] == '-')
            x += pot; 
        pot *= 2;
    }
    return x;
}

int main () {
    while (scanf ("%d %d", &n, &p) && n != 0 && p != 0) {
        int x, y;
        for (int i = 0; i < p; i++) {
            scanf ("%d %s %s", &cost, s1, s2);
        }
    }
}
