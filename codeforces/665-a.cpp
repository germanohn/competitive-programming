#include<bits/stdc++.h>
#define saida first
#define chega second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;
int a, ta, b, tb, hour, mi, ans;

int main () {
    scanf ("%d %d %d %d", &a, &ta, &b, &tb);
    scanf ("%d:%d", &hour, &mi);
    int saida = hour*60 + mi;
    for (int i = 5*60; i < 24*60; i += b) {
        if (i + tb > saida && i < saida + ta)
            ans++;
    }    
    printf ("%d\n", ans);
}
