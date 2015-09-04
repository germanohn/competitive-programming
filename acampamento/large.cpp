#include <cstdio>
#include <algorithm>
#include <climits>
#define MAX 100005

using namespace std;

int n;

int main(){

        struct forma{
                int pos, valor;
        };

        forma v[MAX], novo[MAX];
        int tmp[MAX], aux[MAX], i, j, k, x, y, tam;
        int com, ini, fim, cont, maior, dif, a, menor = INT_MAX, small, l;
        
        scanf("%d", &n);
        
        for(i = 1; i <= n; i++){
                scanf("%d", &a);
                tmp[i] = a;
                v[i].valor = a;
                v[i].pos = i;
        }

        sort(tmp + 1, tmp + n + 1);
        
        for(i = 1; i <= n; i++) printf("%d ", tmp[i]);

        printf("\n");
        maior = 0;
        cont = 1;
        i = 1;
        while(i <= n){
                dif = 0;
                cont = 1; 
                for(j = i + 1; j < n && !dif; j++){
                        if(tmp[i] == tmp[j]){
                                cont++;
                                if(cont > maior) maior = cont;
                        }
                        else dif = 1;
                }
                i = j;
        }
        printf("%d\n", maior);        

        i = 1;
        while(i < n){
                com = v[1].pos;
                k = 1; 
                cont = 1;
                small = 0;
                for(j = i + 1; j < n && !small; j++){
                        if(v[j].valor == v[i].valor){
                                fim = j;
                                cont += 2;
                                if(cont == maior) small = 1;
                        }     
                        else{
                                novo[k] = v[j];
                                k++;
                        }
                }
                tam = fim - com;
                if(menor > tam){
                        menor = tam;
                        x = ini;
                        y = fim;
                }
                for(l = 1; l <= k; l++) v[l] = novo[l];

                i = v[1].pos;
        }
        printf("%d %d\n", x, y);
}
    
                


