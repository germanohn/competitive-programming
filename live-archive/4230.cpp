#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 212;
const int inf = 1000000;

int r, c;
int totalSpaces, numSpaces[MAX*MAX], accNumSpaces[MAX*MAX];
double averageDist[MAX*MAX], expVal;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char grid[MAX][MAX];
int dis[MAX][MAX];
pii st, fim;

bool can (int a, int b) {
    if (a < 0 || a >= r || b < 0 || b >= c || grid[a][b] == 'X')
       return false;
    return true; 
}

void bfs () {
    queue<pii> q;
    for ( int i = 0; i < r; i++ )
        for ( int j = 0; j < c; j++ ) {
            if (grid[i][j] == 'E') {
                q.push (pii (i, j));
                dis[i][j] = 0;
            } 
            if (grid[i][j] != 'E') 
                dis[i][j] = inf;
        }
    while (!q.empty ()) {
        pii a = q.front ();
        q.pop ();
        for (int i = 0; i < 4; i++) {
            pii nx = pii (a.ff + dx[i], a.ss + dy[i]);
            if (can (nx.ff, nx.ss) && dis[nx.ff][nx.ss] > dis[a.ff][a.ss]+1) {
                dis[nx.ff][nx.ss] = dis[a.ff][a.ss]+1;
                q.push (nx);   
            }
        }
    }
}

void clear () {
    totalSpaces = 0;
    for (int i = 0; i < MAX*MAX; i++) 
        numSpaces[i] = accNumSpaces[i] = 0;
}

int main () {
    while (scanf ("%d %d", &r, &c)) {
        if (r == 0 && c == 0) 
            break;
        clear ();
        char ch;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf (" %c", &grid[i][j]);
                if (grid[i][j] != 'X')
                    totalSpaces++;
                if (grid[i][j] == 'Y')
                    st = pii (i, j);
                if (grid[i][j] == 'E') {
                    fim = pii (i, j);
                }
            }
        }
        bfs ();
        // numSpaces
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++) 
                if (dis[i][j] < inf) 
                    numSpaces[dis[i][j]]++;

        // calcular accNumSpaces 
        accNumSpaces[0] = numSpaces[0];
        averageDist[0] = 0;
        for (int i = 1; i < totalSpaces; i++) {
            accNumSpaces[i] = numSpaces[i] + accNumSpaces[i-1];
            averageDist[i] = i * numSpaces[i] + averageDist[i-1];
        }
        for (int i = 0; i < totalSpaces; i++) 
            averageDist[i] = (double) averageDist[i]/accNumSpaces[i];

        double minExpVal = inf;
        int ansDist = 0;
        for (int dist = 0; dist < totalSpaces; dist++) {
            // expVal é a média de passos dados caminhando a partir de distancias
            // menores que dist, mais 1 sobre a probabilidade de cair em um região 
            // cujas distancias pra saida é menor ou igual a dist
            double expVal = 1.0 * (double) totalSpaces / accNumSpaces[dist];
            expVal += 1.0 * (double) averageDist[dist]; 
            if (expVal < minExpVal) {
                minExpVal = expVal;
                ansDist = dist;
            }
        }
        //printf ("ansDist %d dis %d\n", ansDist, dis[st.x][st.ss]);
        double ans;
        if (dis[st.ff][st.ss] <= ansDist) 
            ans = dis[st.ff][st.ss];
        else
            ans = minExpVal;
        printf ("%.3lf\n", ans);
    }
}

