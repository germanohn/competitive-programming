#include <stdio.h>

int main(){

        int caixa[10], c, n, t, d, i, cont = 0, menor;

        scanf("%d %d", &c, &n);

        for(i=0; i<c; i++) caixa[i] = 0;

        menor = 0;
        while(n > 0){

                scanf("%d %d", &t, &d);

                for(i=0; i<c; i++){
                       
                        if(caixa[i] < caixa[menor])
                                menor = i;
                }
                
                if(caixa[menor] - t > 20) cont ++;                

                caixa[menor] += d;

                n--;
        }
        printf("%d\n", cont);
        return 0;
}
