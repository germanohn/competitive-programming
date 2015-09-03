#include <cstdio>
#include <algorithm>
#define MAX 405
 
using namespace std;
 
struct table{
        int tempo;
        bool evento;
        bool esta;
};
 
table trem[MAX];
int n, t, na, nb, a = 0, b = 0, senda = 0, sendb = 0, h, m, tam, i, cont;
 
bool compare(table trem1, table trem2){
        if(trem1.tempo != trem2.tempo)
                return trem1.tempo < trem2.tempo;
        else
                return trem1.evento;
                
} 
 
int main(){
        
        scanf("%d", &n);
 
        cont = 1;
        while(n--){
                scanf("%d %d %d", &t, &na, &nb);
        
                tam = 0;
                a = 0;
                b = 0;
                senda = 0;
                sendb = 0;
                i = 0;
                int aux_a = na;
                while(aux_a--){
                        scanf("%d:%d", &h, &m);
                        trem[i].tempo = 60*h + m;
                        trem[i].evento = false;
                        trem[i].esta = true;
                        i++;
                        scanf("%d:%d", &h, &m);
                        trem[i].tempo = 60*h + m + t;
                        trem[i].evento = true;
                        trem[i].esta = false;
                        i++;
                }
                int aux_b = nb;
                while(aux_b--){
                        scanf("%d:%d", &h, &m);
                        trem[i].tempo = 60*h + m;
                        trem[i].evento = false;
                        trem[i].esta = false;
                        i++;
                        scanf("%d:%d", &h, &m);
                        trem[i].tempo = 60*h + m + t;
                        trem[i].evento = true;
                        trem[i].esta = true;
                        i++;
                }
        
                tam = 2*(na + nb); 
                sort(trem, trem + tam, compare);                              
 
                for(i = 0; i < tam; i++){
                        
                        if(trem[i].evento){
                                if(trem[i].esta)
                                        a += 1;
                                else
                                        b += 1;
                        }
 
                        else{
                                if(trem[i].esta){
                                        if(a > 0) a--;
 
                                        else senda++;
                                }
                                
                                else{
                                        if(b > 0) b--;
        
                                        else sendb++;
                                }
                        }
                }
                printf("Case #%d: %d %d\n", cont, senda, sendb);
                cont ++;
               
        }
}