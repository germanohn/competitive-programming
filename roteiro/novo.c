#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 10010
#define MAXM 30

int N, T;

char nomes[MAXN][MAXM];
int habilidade[MAXN];

int ordem[MAXN];

int time[MAXN];

bool compara(int i, int j) {
    return habilidade[i] > habilidade[j];
}

bool compara2(int i, int j) {
    return strcmp(nomes[i], nomes[j]) < 0;
}

int main(void) {

    scanf("%d%d", &N, &T);

    for(int i = 0; i < N; ++i) {
        scanf("%s %d", nomes[i], habilidade+i);
        ordem[i] = i;
    }

    sort(ordem, ordem+N, compara);

    for(int i = 0; i < T; ++i) {
        printf("Time %d\n", i+1);
        int K = 0;
        for(int j = i; j < N; j += T) {
            time[K++] = ordem[j];
        }
        sort(time, time+K, compara2);
        for(int j = 0; j < K; ++j) {
            printf("%s\n", nomes[time[j]]);
        }
        printf("\n");
    }

    return 0;
}