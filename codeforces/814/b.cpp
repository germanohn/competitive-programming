#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;

int n;
int a[N], b[N], p[N];
int freq[N];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
        p[i] = a[i];
        freq[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        scanf(" %d", &b[i]);
    }

    int last;
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) 
            last = i;
    }

    for (int i = 0; i < n; i++) {
        if (freq[a[i]] == 2) {
            p[i] = last;
            int dif = 0;
            for (int j = 0; j < n; j++) {
                if (p[j] != b[j])
                    dif++;
            }
            if (dif == 1) {
                for (int k = 0; k < n; k++) 
                    printf("%d ", p[k]);
                printf("\n");
                return 0;
            } else {
                p[i] = a[i];
            }
        }
    }
}

