#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
int hour[100][100];

int main () {
    scanf(" %d", &n);
    int cont = 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        hour[a][b]++;
        cont = max(cont, hour[a][b]);
    }
    printf("%d\n", cont);
}

