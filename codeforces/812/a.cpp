#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t[5][5];
int d[3] = {0, 1, 2};

int main () {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf(" %d", &t[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        bool ok = false;
        if (t[i][3] == 0) 
            continue;
        if (t[i][0] == 1 || t[i][1] == 1 || t[i][2] == 1) 
            ok = true;
        int cont = 0;
        for (int j = (i + 1) % 4; !ok && cont < 3; j = (j + 1) % 4, cont++) {
            if (t[j][cont] == 1)
                ok = true;
        }

        if (ok) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
}

