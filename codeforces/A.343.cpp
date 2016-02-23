#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct tipo {
    int m, h;
};

tipo v[5005];
int n, ini, fim;
char gender;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %c %d %d", &gender, &ini, &fim);
        if (gender == 'F')
            for (int j = ini; j <= fim; j++)
                v[j].m++;
        else 
            for (int j = ini; j <= fim; j++)
                v[j].h++;
    }
    int ans = INT_MIN;
    for (int i = 1; i <= 366; i++) { 
        //printf ("dia %d mulher %d homem %d\n", i, v[i].m, v[i].h);
        ans = max (ans, min (v[i].m, v[i].h));
    }
    printf ("%d\n", 2*ans);
}
