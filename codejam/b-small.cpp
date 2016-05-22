#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, B, M;
int A[55][55];

int main () {
    scanf ("%d", &t);
    int cont = 1;
    while (t--) {
        bool f = false;
        memset (A, 0, sizeof A);
        scanf ("%d %d", &B, &M);
        printf ("Case #%d: ", cont++);
        for (int i = 1; i < B; i++) {
            A[i][i+1] = 1;
        }
        M--;
        if (M == 0) 
            f = true;
        for (int i = 1; !f && i < B; i++) {
            for (int j = i+2; !f && j <= B; j++) {
                if (i == j) continue;
                A[i][j] = 1;
                M--;
                if (M == 0)
                    f = true;
            }
        }
        if (M == 0) 
            f = true;
        if (f) {
            printf ("POSSIBLE\n");
            for (int i = 1; i <= B; i++) {
                for (int j = 1; j <= B; j++) {
                    printf ("%d", A[i][j]);
                }
                printf ("\n");
            }
        } else {
            printf ("IMPOSSIBLE\n");
        }
    }
}

