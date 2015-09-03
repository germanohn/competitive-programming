#include <cstdio>
#include <climits>

using namespace std;

int main () {
    int n, m, ordem = 1, v[10004],x,y;
    int menor, maior;
    while (scanf ("%d%d", &n, &m) && n != 0) {
        for(int i = 0; i < n; i++)
            scanf("%d",&v[i]);

        menor = INT_MAX, maior = INT_MIN;
        for (int i = 0; i <= n - m; i++) {
            int media = 0;
            
            for(int j = i; j < m+i; j++)
                media += v[j];
            media /= m;
            //printf("media %d menor %d\n",media,menor);
            if(media < menor)
                menor = media;
            if(media > maior)
                maior = media;
        }
        printf ("Teste %d\n%d %d\n\n", ordem++, menor, maior);
    }
}