#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n;
int a[MAX], pai[MAX], edge[MAX], ans[MAX];
int bit[MAX];
vector<int> seg[MAX];
multiset<int> m;



int main () {
    scanf(" %d", &n);

    for (int i = 0; i < n; i++) 
        scanf(" %d", &a[i]);

    pai[1] = 1;
    for (int i = 1; i < n; i++) {
        int p, a;
        scanf(" %d %d", &p, &a);
        pai[i + 1] = p;
        edge[i + 1] = a;
    }

    for (int i = 1; i <= n; i++) {
        if (pai[i] != 1 && pai[i] != 0) {
            // estou em uma folha
            int son = i, acc_edge = 0;
            while (pai[son] != son) {
                // nao estou na raiz
                seg[i].pb(son);
                son = pai[son];
            }
            sort(seg[i].begin(), seg[i].end());
        }
    }

    for (int i = 1; i <= n; i++) {
        if (pai[i] != 1 && pai[i] != 0) {
            // estou em uma folha
            int son = i, acc_edge = 0;
            limpa();
            while (pai[son] != son) {
                // nao estou na raiz
                acc_edge += edge[son];
                qtd = seg[i].size() - (lower_bound(seg[i].begin(), seg[i].end(), acc_edge) - seg[i].begin())
                ans[pai[son]] = qtd;
                m.insert(a[pai[son]]);
                son = pai[son];
            }
        }
    }

    for (int i = 1; i <= n; i++) 
        printf("%d ", ans[i]);
    printf("\n");
}

/*
 *
 *
 *
 *
 *
 *
 * */
