#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool evil_r[15], evil_c[15];

int main () {
    int r, c;
    char cake[15][15];

    scanf(" %d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %c", &cake[i][j]);
            if (cake[i][j] == 'S') evil_r[i] = true, evil_c[j] = true;
        }
    }

    int cont = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (cake[i][j] == '.' && (!evil_r[i] || !evil_c[j]))
                cont++;
        }
    }

    printf("%d\n", cont);
}

