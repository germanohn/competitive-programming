#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int n, m;
bool has[MAX];
vector<int> toy;

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a;
        scanf ("%d", &a);
        if (a < MAX)
            has[a] = true;
    }
    int ans = 0;
    int k = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (!has[i]) {
            if (m-i >= 0) {
                ans++;
                toy.pb (i);
                m -= i;
            } else {
                break;
            }
        }
    }
    int tam = toy.size (); 
    printf ("%d\n", tam);
    for (int i = 0; i < toy.size (); i++) {
        printf ("%d ", toy[i]);
    }
    printf ("\n");
}

