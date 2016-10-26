#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 100005;

int n, k;
int v[MAX], seen[MAX];

int main () {
    int cont, l;
    int ans, ans_l, ans_r;

    ans = MAX, l = 0, cont = 0;
    memset(seen, -1, sizeof seen);

    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);

    for (int i = 0; i < n; i++) {
        if (seen[v[i]] < l) 
            cont++;
        seen[v[i]] = i;

        while (seen[v[l]] > l || (seen[v[l]] == l && cont > k)) {
            if (seen[v[l]] == l) cont--;
            l++;
        }

        if (cont == k && ans > i - l + 1) {
            ans = i - l + 1;
            ans_l = l + 1, ans_r = i + 1;
        }
    }

    if (ans != MAX) printf("%d %d\n", ans_l, ans_r);
    else printf("-1 -1\n");
}

/* Ideia do tutorial (na minha solucao acima eu encontro o menor de 
 * todos os minimal inclusion segment, e nao so um deles qualquer
int n, k;
int freq[MAX], v[MAX];

int main () {
    scanf(" %d %d", &n, &k);
    int cont = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        if (freq[v[i]] == 0) cont++;
        freq[v[i]]++;
    }

    if (cont < k) {
        printf("-1 -1\n");
        return 0; 
    }

    int l = 0, r = n - 1;
    while (cont >= k) {
        freq[v[r]]--;
        if (freq[v[r]] == 0) cont--;
        r--;
    }
    r++, cont++, freq[v[r]]++;

    while (cont >= k) {
        freq[v[l]]--;
        if (freq[v[l]] == 0) cont--;
        l++;
    }
    l--, cont++;

    printf("%d %d\n", l + 1, r + 1);
}
*/

