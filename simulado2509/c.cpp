#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int bit[2*N+17], v[N];
int n,t,q,m;

int query(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

void update(int idx){
    for(int i = idx; i <= 2*N+16; i += i&-i)
        bit[i]++;
}
void remove(int idx){
    for(int i = idx; i <= 2*N+16; i += i&-i)
        bit[i]--;
}

void show(){
    for(int i = 1; i <= n; i++)
        printf("%d ",v[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(bit,0,sizeof bit);
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= n; i++){
            v[i] = N+i;
            update(v[i]);
        }
        for(int i = 0; i < m; i++){
            scanf("%d",&q);
            printf("%d%c",query(v[q]-1),i == m-1 ? '\n' : ' ');
            update(N-i);
            remove(v[q]);
            v[q] = N-i;
        }
    }
}
