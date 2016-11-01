#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

int n, a1, b1;
vector<pii> pto;

bool verify(pii a, pii b) {
    if ((a.y - b1) * (b.x - a1) == (b.y - b1) * (a.x - a1)) return true;
    return false;    
}

int main() {
    scanf(" %d %d %d", &n, &a1, &b1);
    for (int i = 0; i < n; i++) {
        pii novo;
        scanf(" %d %d", &novo.x, &novo.y);
        bool appear = false;
        for (int j = 0; !appear && j < pto.size (); j++) 
            appear = verify(novo, pto[j]);
        if (!appear) pto.pb(novo);
    }

    printf("%d\n", pto.size ());
}
