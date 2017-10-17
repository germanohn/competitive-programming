#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void find_divisors(int x, vector<int> &divX) {
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divX.pb(i);
            divX.pb(x / i);
        }
    }
}

int main() {
    int a, b, n;
    vector<int> divA, divB;
    scanf(" %d %d %d", &a, &b, &n);
    
    find_divisors(a, divA);
    find_divisors(b, divB);

    sort(divA.begin(), divA.end());
    sort(divB.begin(), divB.end());

    int pA = 0, pB = 0;    
    vector<int> divC;
    while (pA < divA.size() && pB < divB.size()) {
        if (divA[pA] < divB[pB])
            pA++;
        else if (divA[pA] == divB[pB]) {
            divC.pb(divA[pA]);
            pA++, pB++;
        } else 
            pB++;
    }

    while (n--) {
        int lo, hi;
        scanf(" %d %d", &lo, &hi);
        if (!divC.size()) printf("-1\n");
        else {
            hi = upper_bound(divC.begin(), divC.end(), hi) - divC.begin() - 1;
            if (divC[hi] >= lo) printf("%d\n", divC[hi]);
            else printf("-1\n");
        }
    }
}

