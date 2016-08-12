#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 500;

ll cop[MAX], a[5], m[5], m_barra[5], m_inverse[5];

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n, pos = 0, qtd_coprimes;
        char ans[500];
        qtd_coprimes = 4;
        scanf ("%d", &n);
        for (int i = 0; i < qtd_coprimes; i++) scanf ("%lld", &cop[i]);
        for (int i = 0; i < n; i++) {
            char s[10];
            int k = 0, len, ini;
            scanf (" %s", &s);
            len = strlen (s);
            if (len == 7) a[k++] = s[0]-'0', ini = 1;
            else a[k++] = (s[0]-'0')*10 + s[1]-'0', ini = 2;
            for (int j = ini; j < 7; j += 2) 
                a[k++] = (s[j]-'0')*10 + s[j+1]-'0';

            for (int j = 0; j < qtd_coprimes; j++) {
                m[j] = 1;
                for (int l = 0; l < qtd_coprimes; l++) {
                    if (l == j) continue;
                    m[j] *= cop[l];
                }
                m_barra[j] = m[j] % cop[j];
                for (int l = 1; l < cop[j]; l++)
                    if ((m_barra[j]*l) % cop[j] == 1) {
                        m_inverse[j] = l;
                        break;
                    }
            }

            ll mod = 1;
            for (int j = 0; j < qtd_coprimes; j++) mod *= cop[j];
            ll aux = 0;
            for (int j = 0; j < qtd_coprimes; j++) 
                aux = (aux + a[j]*((m[j]*m_inverse[j]) % mod)) % mod;
           
            char str[5]; 
            for (int j = 0; j < 3; j++) {
                int num = aux % 100;
                aux /= 100;
                if (num > 26) str[j] = ((char) ' ');
                else str[j] = ((char) (num-1 + 'A'));
            }

            for (int j = 2; j >= 0; j--) 
                ans[pos++] = str[j];
        }
        for (int i = pos-1; i >= 0; i--) {
            if ( ans[i] == ' ' ) pos--;
            else break;
        }
        ans[pos] = '\0';
        cout << ans << endl;
    }
}
