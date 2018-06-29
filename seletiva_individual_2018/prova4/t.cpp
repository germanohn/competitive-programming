#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

struct pii {
    int a, b;

    pii() {}
    pii(int ai, int bi) : a(ai), b(bi) {}

    bool operator< (pii x) const {
        if (a < x.a)
            return true;
        return b < x.b;
    }   
};

int main() {
    set<pii> s;
    int a, b;
    scanf(" %d %d", &a, &b);
    s.insert(pii(a, b));
}

