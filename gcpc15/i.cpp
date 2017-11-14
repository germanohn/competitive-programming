#include<bits/stdc++.h>
using namespace std;

const int W = 10004;
const int X = 102;
int w, s, x, y;
int work[W][X];
int step[X];

int main() {
    scanf("%d %d", &w, &s);
    scanf("%d %d", &x, &y);
    
    for(int i = 0; i < w; i++)
        for(int j = 0; j < x; j++)
            scanf("%d", &work[i][j]);

    for(int i = 0; i < s; i++) {
        for(int j = 0; j < x; j++) {
            int st;
            scanf("%d", &st);
            step[j] = max(step[j], st);
        }
    }
    for(int i = 0; i < w; i++)
        for(int j = 0; j < x; j++)
            printf("%d%c", min(y - step[j], work[i][j]), j == x-1 ? '\n' : ' ');
}

