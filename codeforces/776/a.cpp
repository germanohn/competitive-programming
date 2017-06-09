#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 15;

int n;
char victim[2][N];
char killed[N], nw[N];

int main () {
    scanf(" %s %s", victim[0], victim[1]);
    scanf(" %d", &n);
    printf("%s %s\n", victim[0], victim[1]);
    for (int i = 0; i < n; i++) {
        scanf(" %s %s", killed, nw);
        if (strcmp(killed, victim[0]) == 0) 
            strcpy(victim[0], nw);
        else 
            strcpy(victim[1], nw);
        printf("%s %s\n", victim[0], victim[1]);
    }
}

