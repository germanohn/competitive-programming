#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

char a[MAX], b[MAX];

int main () {
    scanf(" %s %s", a, b);
    int len_a = strlen(a), len_b = strlen(b);
    if (len_a != len_b) {
        printf("%d\n", max(len_a, len_b));
    } else {
        bool ok = true;
        for (int i = 0; ok && i < len_a; i++) {
            if (a[i] != b[i])
                ok = false;
        } 
        if (!ok) printf("%d\n", len_a);
        else printf("-1\n");
    }
}

