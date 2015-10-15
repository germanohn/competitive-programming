#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007

using namespace std;

char maior[MAX], seq[MAX];
int memo[MAX], M, S;

/*bool ordena (int i, int j) {
    if (j - i + 1 < M) return true;//se for menor que limitante M
    
    else if (j - i + 1 > M) return false;//se for maior que o limitante M

    while (i <= j && maior[i] == seq[i]) 
        i++;
    if (i > j) return true;
    if (seq[i] < maior[i]) return true;
    return false;
    if (strncmp (seq + j, maior, M) > 0)
        return false;
    return true;
    
}*/

int pd (int i) {
    if (seq[i] == '\0') return 1;
    
    if (seq[i] == '0') return 0;
    
    int &m = memo[i], tot = 0;
    if (m != -1) return m;
     
    for (int j = i; j < S; j++) {     

        /*if (ordena (i, j))
            tot .....*/
       if (j - i + 1 > M) break;
       if (j - i + 1 == M) {
            if (strncmp (seq + i, maior, M) > 0) 
                break;     
       }
       
        tot = (tot + pd (j + 1)) % MOD;
       
    }
    return m = tot;
    
}

int main () {
    memset (memo, -1, sizeof (memo));

    scanf ("%s %s", maior, seq);
    
    M = strlen (maior);
    
    S = strlen (seq);

    printf ("%d\n", pd (0));   
}
