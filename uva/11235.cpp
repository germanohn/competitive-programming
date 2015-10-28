#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, q, num, k, in[N], freq[N], ff[N];
int tree[4*N];
map<int, int> m;

/* e uma arvore com a freq dos numeros distintos*/
void build (int node, int l, int r, int val) {
    if (l == r) {
        tree[node] = freq[val];
    }
    else {
        int mid = (l+r)/2;
        if (val <= mid) build (2*node, l, mid, val);
        else build (2*node + 1, mid+1, r, val);
        tree[node] = max (tree[2*node], tree[2*node+1]);
    }
}

int query (int ini, int fim, int node, int l, int r) {
    if (l > fim || r < ini) return 0;
    if (l >= ini && r <= fim) return tree[node];
    int mid = (l+r)/2;
    return max (query (ini, fim, 2*node, l, mid), query (ini, fim, 2*node + 1, mid+1, r));

}

int main () {
    while (scanf ("%d", &n) && n != 0) {
        scanf ("%d", &q);
        m.clear ();
        for (int i = 0; i <= n; i++) 
            freq[i] = 0;
        int k = 1;
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &num);
            if (!m[num]) m[num] = k++;
            num = m[num];
            in[i] = num;
            freq[num]++;
            if (freq[num] == 1) ff[num] = i;
        }

        for (int i = 1; i < k; i++) {
            build (1, 1, k-1, i);
        }

        int ini, fim;
        for (int i = 0; i < q; i++) {
            scanf ("%d %d", &ini, &fim);
            if (in[ini] == in[fim]) printf ("%d\n", fim-ini+1);
            else {
                int maxi = max (freq[in[ini]]-ini+ff[in[ini]], fim-ff[in[fim]]+1);//esse maxi é freq max entre os numeros das pontas
                if (in[ini]+1 == in[fim]) 
                    printf ("%d\n", maxi);
                else {/* agora sera o maximo entre o de freq maior nas pontas e o de freq maior no meio, isto e, tirando as pontas*/
                    printf ("%d\n", max (maxi, query (in[ini]+1, in[fim]-1, 1, 1, k-1)));
                }
            }
        }
    }
}
