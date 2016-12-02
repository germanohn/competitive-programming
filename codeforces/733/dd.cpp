#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

multiset<int> m;

int main () {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        m.insert(a);
    }

    m.erase(prev(m.end()), m.end());

    for (multiset<int>::iterator it = m.begin(); it != m.end(); it++) {
        printf("%d \n", *it);
    }
    printf("\n");
}

