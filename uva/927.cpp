#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t;
int v[55];

int main () {
    scanf ("%d", &t);
    while (t--) {
        char str[50];
        gets (str);
        int i = 0, k = 0;
        while (str[i] != 0) {
            if (str[i] == ' ') {
                i++; 
                continue;
            }
            if (str[i+1] != 0 && str[i+1] != ' ')
                v[k++] = str[i]
            v[k++] = str[i] - '0'; 
            i++;
        }
        for (i = 0; i < k; i++) 
            printf ("%d ", v[i]);
        printf ("\n");
    }
}

