#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1e6 + 5;

int p[N];
vector<int> lucky;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (!p[i]) 
            for (int j = i; j < N; j += i)
                p[j] = i;   
    }
}

int main() {
    sieve();
    for (int i = 30; i < N; i++) {
        int aux = i;
        set<int> s;
        while (aux > 0 && aux != 1) {
            s.insert(p[aux]);       
            aux /= p[aux];
        }
        int sz = s.size();
        if (sz >= 3) 
            lucky.pb(i);
    }

    int t;
    scanf(" %d", &t);
    while (t--) {
        int n;
        scanf(" %d", &n);
        printf("%d\n", lucky[n - 1]);
    }
}
