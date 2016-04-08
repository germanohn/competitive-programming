#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int bus[105][5];

int main () {
    int num = 1, col1[2] = {0, 3};
    scanf ("%d %d", &n, &m);
    for (int i = n-1; i >= 0 && num <= m; i--) {
        for (int j = 0; j < 2; j++) {
            bus[i][col1[j]] = num++;
            if (num == m+1) 
                break;    
        }
    }
    int col2[2] = {1, 2};
    for (int i = n-1; i >= 0 && num <= m; i--) {
        for (int j = 0; j < 2; j++) {
            bus[i][col2[j]] = num++;
            if (num == m+1) 
                break;
        }
    }
    int col3[4] = {1, 0, 2, 3};
    for (int i = n-1; i >= 0 && m >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (bus[i][col3[j]] == 0) continue;
            printf ("%d ", bus[i][col3[j]]);
            m--;
            if (m == -1) 
                break;
        }
    }
    printf ("\n");
}
