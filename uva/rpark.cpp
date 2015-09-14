#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#define MAX 3005
#define pb push_back
#define mp make_pair

using namespace std;

int n, a, b, maxi, mini, cont;
vector<pair<int, int> > par;

int main () {
    while (scanf ("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) { 
            scanf ("%d %d", &a, &b);
            par.pb (mp (a, b));
        }
        cont = 0;
        sort (par.begin (), par.end ());
        for (int i = 0; i < n; i++) {
            maxi = INT_MAX;
            mini = INT_MIN;
            for (int j = i - 1; j >= 0; j--) {
                if (par[j].second < maxi && par[j].second > par[i].second) {
                    cont++;
                    maxi = par[j].second;
                }
                else if (par[j].second > mini && par[j].second < par[i].second) { 
                    cont++;
                    mini = par[j].second;
                }
            }
        }
        printf ("%d\n", cont);
        par.clear ();
    }
}
