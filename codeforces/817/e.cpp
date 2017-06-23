#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int q;
int cont;
int trie[32 * N][3];

void update(int k, int pi) {
    int no = 1;
    for (int i = 31; i >= 0; i--) {
        trie[no][2] += k;
        bool bit = !!((1 << i) & pi);
        if (trie[no][bit] == 0) 
            trie[no][bit] = cont++;
        no = trie[no][bit];   
    }
    trie[no][2] += k;
}

int query(int pi, int li) {
    int no = 1, ans = 0;
    for (int i = 31; i >= 0; i--) {
        bool bit_li = !!((1 << i) & li);
        int bit_pi = !!((1 << i) & pi);
        if (bit_li) {
            ans += trie[trie[no][bit_pi]][2];
            no = trie[no][!bit_pi];
        } else {
            no = trie[no][bit_pi];
        }
    }
    return ans;
}

int main () {
    scanf(" %d", &q);

    cont = 2;
    while (q--) {
        int ki, pi;
        scanf(" %d %d", &ki, &pi);
        if (ki == 1) {
            update(1, pi); 
        } else if (ki == 2) {
            update(-1, pi);
        } else {
            int li;
            scanf(" %d", &li);
            printf("%d\n", query(pi, li));
        }
    }
}

