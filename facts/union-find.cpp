#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int find (int a) {
    if (a == pai[a]) return a;
    return pai[a] = find (pai[a]);
}

bool join (int a, int b) {
    a = find (a), b = find (b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap (a, b);
    pai[b] = pai[a];
    sz[a] += sz[b];
    return true; 
}

int main () {

}

