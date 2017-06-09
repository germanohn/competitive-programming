#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;

char n[N];

int main () {
    scanf(" %s", n);
    for (int i = 0; i < 1000; i += 8) {
        bool ok = true;
        char aux[5];
        sprintf(aux, "%d", i);
        if (strlen(aux) > strlen(n)) 
            break;
        int p = 0;
        for (int j = 0; aux[j] != 0; j++) {
            while (n[p] != aux[j] && n[p] != 0)
               p++;
            if (n[p] != aux[j]) {
               ok = false;
               break; 
            }
            p++;
        }
        if (ok) {
            printf("YES\n%d\n", i);
            return 0;
        }
    }
    printf("NO\n");
}

