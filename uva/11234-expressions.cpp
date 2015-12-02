/* -operando sao folhas. nao tem como um operando ser pai de um operador
// -construo um vetor ans que é a ordem dos indices da str a serem lidos
// para ter a rta.
// -*/ 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

const int MAX = 100005;

stack<int> s;
vector<int> adj[MAX];
int ans[MAX];
char str[MAX];

void bfs (int a) {
    queue<int> q;
    q.push(a);
    int k = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans[k++] = x;
        for (int i = 0; i < adj[x].size(); i++) {
            q.push(adj[x][i]);
        }        
    }
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--){
        scanf (" %s", str);
        int k = strlen (str);
        for (int i = 0; str[i] != 0; i++) {
            adj[i].clear();
            if (isupper (str[i])) {
                int a, b;
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                adj[i].pb (b);
                adj[i].pb (a);
            }
            s.push(i);
        }
        bfs (k-1);
        for (int i = k-1; i >= 0; i--) {
            printf ("%c", str[ans[i]]);
        }
        printf ("\n");
    }
}
