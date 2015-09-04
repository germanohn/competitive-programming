#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
#define MAX 305
#define MAXN 20005

using namespace std;

int n, tam, m[MAX][MAXN], v[MAX], k, rta[MAX];

int pd(int c, int l, int r){

    if(c == tam) return 0;

    if(m[c][l] != -1) return m[c][l];

    int ret = 0;
    if(v[c] <= l)
        ret = max(ret, pd(c + 1, l - v[c], r) + 1);
    if(v[c] <= r)
        ret = max(ret, pd(c + 1, l, r - v[c]) + 1);

    m[c][l] = ret;
    return ret;
}

void pd2(int c, int l, int r){

    if(c == k) return ;

    int r1 = -INT_MAX, r2 = -INT_MAX;
    if((l - v[c]) >= 0)
        r1 = pd(c + 1, l - v[c], r);
    if((r - v[c]) >= 0)
        r2 = pd(c + 1, l, r - v[c]);
    
    if(r1 >= r2){ 
        rta[c] = 1;
        pd2(c + 1, l - v[c], r);
        return ;
    }    
    else{
        rta[c] = 0;
        pd2(c + 1, l, r - v[c]);
    }
} 

int main(){

    scanf("%d", &n);
    memset(m, -1, sizeof m);
    n = n*100;
    int i = 0;
    int a;
    while(scanf("%d", &a) && a != 0){
        v[i] = a;
        i++;
    }
    tam = i;
    
    k = pd(0, n, n);
    pd2(0, n, n);
    printf("%d\n", k);
    for(i = 0; i < k; i++){
        if(rta[i] == 1)
            printf("port\n");
                
        else if(rta[i] == 0)
            printf("starboard\n");
    }
}    
    
