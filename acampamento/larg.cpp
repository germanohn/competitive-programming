#include <cstdio>
#include <climits>
#define MAX 1000005

using namespace std;

int n;

int main(){

    struct coord{
        int c, u;
    };
    
    coord v[MAX];
    int f[MAX], cand[MAX]; 

    scanf("%d", &n);

    for(int i = 0; i < MAX; i++) f[i] = 0;
    
    int aux = n, max = 0;
    int i = 0, a;
    while(aux--){
        scanf("%d", &a);
        
        if(f[a] == 0){
            v[a].c = i;
            v[a].u = i;
        }
        else v[a].u = i;

        f[a]++;
        if(f[a] > max) max = f[a];
        i++;
    }
    
    int k = 0;
    for(int i = 0; i < MAX; i++){
        if(f[i] == max){
            cand[k] = i;
            k ++;
        }
    }
    
    int dif = INT_MAX, dis, ini, fim;
    for(int i = 0; i < k; i++){
        dis = v[cand[i]].u - v[cand[i]].c;
        if(dis <= dif){
            ini = v[cand[i]].c; 
            fim = v[cand[i]].u;
            dif = dis;
        }
    }
    
    printf("%d %d\n", ini + 1, fim + 1);
}
    
        
        
        
        
