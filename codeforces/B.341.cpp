#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n;
ll dir, esq;
pii pos[2000005];

int main () {
    scanf ("%d", &n);
    int tam = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> pos[i].ff >> pos[i].ss;
        if (pos[i].ff == pos[i].ss) dir++;
        if (pos[i].ff > tam) tam = pos[i].ff;
        if (pos[i].ss > tam) tam = pos[i].ss;
    }
    for (int i = 0; i < n; i++) 
        if (pos[i].ff+pos[i].ss == tam+1) esq++;
    dir = (dir*(dir-1))/2;
    esq = (esq*(esq-1))/2;
    cout << dir+esq << endl;
}
