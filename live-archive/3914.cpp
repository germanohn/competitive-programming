#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, numFlips;
int v[35], ans[100];
char sinal;

void flip (int pos) {
    numFlips++;
    for (int i = 0; i < (pos+1)/2; i++) {
        int aux = v[i];
        v[i] = -v[pos-i];
        v[pos-i] = -aux;
    }
    if (pos % 2 == 0) {
        v[pos/2] = -v[pos/2];
    }
}

void print (int pos) {
    for (int i = 0; i <= pos; i++)
        printf ("%d ", v[i]);
    printf ("\n");
}

int main () {
    int t = 1;
    scanf ("%d", &n);
    while (n--) {
        scanf ("%d", &m);
        printf ("%d ", t++);
        for (int i = 0; i < m; i++) {
            scanf ("%c", &sinal); 
            scanf ("%d", &v[i]);
            if (sinal < 0)
                v[i] = -v[i];
        }
        
        int num, k;
        numFlips = 0, k = 0;
        for (int num = m; num >= 2; num--) {
            for (int i = 0; i < m; i++) {
                if ((abs (v[i]) == num && i != num-1) || (abs (v[i]) == num && v[i] < 0 && i == num-1)) {
                    //printf ("\nMuda\n");
                    int pos = i;
                    if (pos != 0) {
                        flip (pos);
                     //   print (m-1);
                        ans[k++] = pos+1;
                    }    
                    if (v[0] > 0) {
                        numFlips++;
                        v[0] = -v[0];
                        ans[k++] = 1;
                    }
                    ans[k++] = abs (v[0]);
                    flip (abs (v[0]) - 1);
                    //print (m-1);
                    break;
                }
            }
            //print (m-1);
        }
        if (v[0] < 0) {
            numFlips++;
            ans[k++] = 1;
        }
        printf ("%d ", numFlips);
        for (int i = 0; i < k; i++) 
            printf ("%d ", ans[i]);
        printf ("\n");
    }
}

