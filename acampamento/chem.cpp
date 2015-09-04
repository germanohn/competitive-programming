#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#define MAX 100005

using namespace std;

int alc[MAX], cto[MAX], v[MAX];

int expande(int n, int cont){
    while(n <=100005){    
        alc[n]++;
        cto[n] += cont;
        cont++;
        n *= 2;
    }
}

int main(){

        int n, menor = INT_MAX;
        memset(alc, 0, sizeof alc), memset(cto, 0, sizeof cto);
        scanf("%d", &n);

        for(int i = 0; i < n; i++) scanf("%d", &v[i]); 
        
        for(int i = 0; i < n; i++){
            int ndiv, num, ant;            
            ndiv = 0;    
            num = v[i];
            expande(v[i], ndiv);
            ant = num;            
            num /= 2;
            ndiv++;
            
            while(num > 0){
                if(ant % 2 != 0){
                    expande(num, ndiv);
                }
                else{
                    alc[num]++;
                    cto[num] += ndiv; 
                }
                ant = num;
                num /= 2;
                ndiv++;
            }
        }

        for(int i = 0; i < MAX; i++){

            if(alc[i] == n){                
                if(cto[i] < menor)
                    menor = cto[i];                               
            }
           
        } 
        
        printf("%d\n", menor);
}
      
        

        
