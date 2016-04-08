#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 100000;
const int inf = 100000007;

int mark[MAX], dir[9] = {-5, -4, -3, -1, 0, 1, 3, 4, 5};
int mask, move;
char c;

bool pode (int bit, int sent) {
    if (bit < 4) 
        if (sent >= -5 && sent <= -3) return false;
    if (bit >= 12 && bit <= 15) 
        if (sent >= 3 && sent <= 5) return false;
    if (bit % 4 == 0)
        if (sent == -5 || sent == -1 || sent == 3) return false;
    if ((bit % 4)-3 == 0) 
        if (sent == -3 || sent == 1 || sent == 5) return false; 
    if (bit+sent >= 0 && bit+sent <= 15) return true;
}

int flip (int num, int bit) {
    for (int i = 0; i < 9; i++) {
        if (!pode (bit, dir[i])) continue;
        int posModif = bit+dir[i];
        //printf ("num %d bit %d dir[i] %d\n", num, bit, dir[i]);
        if ((move & (1 << i))) 
            num ^= (1 << posModif);
    }    
    return num;
}

void bfs () {
    queue<int> q;
    q.push (mask);
    while (!q.empty ()) {
        int x = q.front ();
        q.pop ();
        if (x == 0 || x == pow (2, 16) - 1) 
            break;
        //printf ("x %d\n", x);
        for (int i = 0; i < 16; i++) {
            int num = flip (x, i);
            //printf ("centro %d  num %d\n", i, num);
            if (mark[num] == INT_MAX) {
                mark[num] = mark[x]+1;
                q.push (num);
            }
        }
    }
}

int main () {
    int tam = 4;
    for (int i = 0; i < MAX; i++) 
        mark[i] = INT_MAX;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf (" %c", &c);
            if (c == 'W') 
                mask |= (1 << (i*tam + j));
        }
    }
    tam = 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf (" %c", &c);
            if (c == '1') 
                move |= (1 << (i*tam + j));
        }
    }
    mark[mask] = 0;
    bfs ();
    int ans = min (mark[0], mark[(1<<16)-1]);
    if (ans != INT_MAX) 
        printf ("%d\n", ans);
    else printf ("Impossible\n");
}

