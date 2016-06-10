#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 100005;

int n, k;
int v[MAX];

int main () {
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    sort (v, v+n);
    /*for (int i = 0; i < n; i++)
        printf ("%d ", v[i]);
    printf ("\n");*/

    int lo, hi, qtdL, qtdH, mi, mx;
    lo = v[0], hi = v[n-1];
    int cont = 0;
    while (lo != hi) {
        int mid = (lo+hi+1)/2; 
        qtdL = qtdH = 0;
        for (int i = 0; i < n; i++) {
            qtdL += (v[i] < mid) ? mid-v[i] : 0;
            qtdH += (v[i] > mid) ? v[i]-mid : 0;
        }
        printf ("v[mid] %d lo %d hi %d qtdL %d qtdH %d\n", v[mid], lo, hi, qtdL, qtdH);
        if (qtdL > k || qtdH < qtdL) {
            hi = mid-1;
        } else {
            lo = mid; 
        }
    }
   
    /* apos essa busca binaria eu tenho duas coisas: 
    - a linha dos pobres mi
    - qtdL: quantidade de dias necessarios para levar todos os individuos com menos 
    de mi moedas pra mi moedas, e qtdL por construçao respeita o fato que qtdL <= qtdH
    (ou seja, consigo formar essa linha dos pobres) e qtdL <= k (consigo fazer isso em k 
    operaçoes) */
    mi = lo;
    qtdL = 0;
    for (int i = 0; i < n; i++)
        qtdL += (v[i] < mi) ? (mi-v[i]) : 0;
    printf ("qtdL %d mi %d\n", qtdL, v[lo]); 
    
    /* agora preciso achar a menor linha dos ricos mx que me garante duas coisas:
    - qtdL está entre a quantidade máxima de moedas (qtdHmx) que consigo produzir que é colocando
    um rico na linha de ricos e levando todos os outros pra linha dos pobres mi, e 
    quantidade mínima de moedas (qtdHmi) que consigo produzir que é colocando todos os ricos 
    na linha dos ricos */
    int qtdLmi = qtdL;
    hi = v[n-1];
    while (lo != hi) {
        int mid = (lo+hi+1)/2;
        int qtdHmx, qtdHmi;
        bool firstH, firstL = 0;
        firstH = firstL = false;
        qtdHmx = qtdHmi = 0;
        int qtdLmx = 0;
        for (int i = 0; i < n; i++) { 
            if (v[i] > mid) {
                if (firstH) {
                    firstH = false;
                    qtdHmx += v[i]-mid;
                } else {
                    qtdHmx += v[i]-mi;
                } 
                qtdHmi += v[i]-mid;
            }
            if (v[i] < mid) {
                if (firstL) {
                    qtdLmx += lo-v[i]; 
                    firstL = false;
                } else {
                    qtdLmx += mid-v[i];
                }
            }
        }

        if (qtdLmi > qtdHmx) {
            // entao preciso que os ricos empobreçam mais, logo preciso que diminua a linha do mais rico
            hi = mid-1;
        } else if (max (qtdLmx, k) < qtdHmi) {
            // entao preciso que os ricos empobreçam menos
            lo = mid+1;
        } else {
            // entao esta na faixa aceitável, logo vou tentar diminuir a linha dos ricos
            hi = mid; 
        }
        printf ("lo %d hi %d qtdL %d qtdH %d\n", lo, hi, qtdL, qtdH);
    }
    //printf ("lo %d\n", lo);
    mx = v[lo];
    
    printf ("%d\n", mx-mi);
}
