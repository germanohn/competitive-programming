#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 505;

int a[MAX], b[MAX];
vector<pii> ans;

int main () {
    int n, k;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &a[i]);

    scanf(" %d", &k);
    for (int i = 0; i < k; i++) 
        scanf(" %d", &b[i]);

    int j = 0;
    int qtd_dead = 0;
    for (int i = 0; i < k; i++) {
        int acc = 0;
        int start_inter = j - 1;
        int maior = -1, pos_maior;
        for (; acc < b[i] && j < n; j++) {
            acc += a[j];
            if ((a[j] > maior) || (a[j] == maior && ((j - 1 > start_inter && a[j - 1] < a[j]) || (acc < b[i] && j + 1 < n && a[j + 1] < a[j])))) 
                maior = a[j], pos_maior = j;
        }

        if (acc > b[i] || acc < b[i]) {
            printf("NO\n");
            return 0;
        } else {
            int l = pos_maior - 1, r = pos_maior + 1;
            int sum = maior;
            int dead_left = 0, dead_right = 0;

            while (l > start_inter || r < j) {
                if (l > start_inter && a[l] < sum) {
                    ans.pb(pii(pos_maior + 1 - qtd_dead - dead_left, 0));
                    dead_left++;
                    sum += a[l];
                    l--;
                } else if (r < j && a[r] < sum) {
                    ans.pb(pii(pos_maior + 1 - qtd_dead - dead_left, 1));
                    dead_right++;
                    sum += a[r];
                    r++;
                } else {
                    printf("NO\n");
                    return 0;
                }
            }

            qtd_dead += dead_left + dead_right;
        }
    }

    if (j != n) {
        printf("NO\n");
        return 0;
    } 

    printf("YES\n");
    for (int i = 0; i < ans.size (); i++) {
        if (ans[i].ss == 0) 
            printf("%d L\n", ans[i].ff); 
        else 
            printf("%d R\n", ans[i].ff);
    }
}

