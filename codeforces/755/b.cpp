#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int n, m;
string po[MAX], en[MAX];
map<string, int> word;

bool cmp(string a, string b) {
    return word[a] > word[b];
}

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin >> po[i];
        word[po[i]]++;    
    }
    for (int i = 0; i < m; i++) {
        cin >> en[i];
        word[en[i]]++;
    }
    sort(po, po + n, cmp);
    sort(en, en + m, cmp);
    bool turn = 0;
    int p_po = 0, p_en = 0;
    while (p_po + p_en < n + m) {
        if (!turn) {
            while (word[po[p_po]] == 0 && p_po < n) 
                p_po++;
            word[po[p_po]] = 0;
        } else {
            while (word[en[p_en]] == 0 && p_en < m)
                p_en++;
            word[en[p_en]] = 0;
        }
        if ((!turn && p_po == n) || (turn && p_en == m))
            break;
        turn = !turn;
    }
    //printf("turn %d p_po %d p_en %d\n", turn, p_po, p_en);
    if (!turn && p_po == n) printf("NO\n");
    else printf("YES\n");
}

