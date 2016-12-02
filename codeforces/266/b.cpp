#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, t;
char q[55];

int main () {
    scanf(" %d %d", &n, &t);
    scanf(" %s", q);

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (q[j] == 'B' && q[j + 1] == 'G')
                swap(q[j], q[j + 1]), j++;
        }
    }

    printf("%s\n", q);
}

