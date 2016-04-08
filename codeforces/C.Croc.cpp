#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
char s[100005];
int ida[100005], volta[100005];

int main () {
    scanf ("%d %d %s", &n, &k, s);
    int tam = strlen (s), pos;
    bool f = false;
    int pilha[100005], top = 0, ant = -1;
    for (int i = 0; i < tam; i++) {
        if (s[i] == '0') {
            while (top > 0) {
                ida[pilha[--top]] = i;
            }
            if (ant == -1) {
                ant = i;
                continue;
            }
            ida[ant] = i;
            ant = i;
        } else {
            pilha[top++] = i;
        }
    }
    top = 0, ant = -1;
    for (int i = tam-1; i >= 0; i--) {
        if (s[i] == '0') {
            while (top > 0) {
                volta[pilha[--top]] = i;
            }
            if (ant == -1) {
                ant = i;
                continue;
            }
            volta[ant] = i;
            ant = i;
        } else {
            pilha[top++] = i;
        }
    }
    int l = -1, h = 0, i = 0, q = 0; 
    int ans = INT_MAX, aux;
    while (i < tam) {
        if (s[i] == '0') {
            q++;
            // dois momentos pra marcar
            // inicializar o l
            // quando tiver k zeros
            if (l == -1) {
                l = i;
            } else if (q == k+1) {
                q--;
                if (h == 0) { 
                    h = i;
                } else {
                    l = ida[l];
                    h = ida[h];
                }
                if (h == 0) {
                    break;
                } else {
                    int mid = (l+h)/2;
                    if (s[mid] != '0') {
                        int a = ida[mid];
                        a = max (a-l, h-a);
                        int b = volta[mid];
                        b = max (b-l, h-b);
                        aux = min (a, b);
                    } else {
                        aux = max (mid-l, h-mid);
                    } 
                    ans = min (ans, aux);
                }
            } 
        }
        i++;   
    }     
    printf ("%d\n", ans); 
}
