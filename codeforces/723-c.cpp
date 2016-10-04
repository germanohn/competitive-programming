#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 2005;

int n, m;
int v[MAX];
map<int, int> freq;
vector<int> falta;
set<int> sobra;

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        freq[v[i]]++;
    }

    int mini = n/m;
    for (int i = 0; i < n; i++) {
        if (freq[v[i]] > mini || v[i] > m) {
            freq[v[i]]--;
            sobra.insert (i);
        }
        else if (v[i] <= m && freq[v[i]] < mini) {
            freq[v[i]]++;
            falta.pb (v[i]);
        }
    }

    for (int i = 1; i <= m; i++) {
        if (freq[i] < mini)
            for (int j = 0; j < mini-freq[i]; j++) 
                falta.pb (i);
    }

    int num_ch = 0;
    for (int i = 0; i < falta.size (); i++) {
        int pos = *sobra.begin ();
        v[pos] = falta[i];
        sobra.erase (pos);
        num_ch++;
    } 

    printf ("%d %d\n", mini, num_ch);
    for (int i = 0; i < n; i++) 
        printf ("%d ", v[i]);
    printf ("\n");
}

