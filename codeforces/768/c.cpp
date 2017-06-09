#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int X = 1024;

int n, k, x;
int freq[X], aux[X];

int main () {
    scanf(" %d %d %d", &n, &k, &x); 
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        freq[a]++;
    }
    for (int i = 0; i < k; i++) {
        int prev = 0;
        for (int j = 0; j < X; j++) 
            aux[j] = freq[j];
        for (int j = 0; j < X; j++) {
            if (!aux[j])
                continue;
            int nx = j ^ x, ch;
            if (prev % 2 == 0) 
                ch = (aux[j] + 1) / 2;
            else 
                ch = aux[j] / 2;
            freq[j] -= ch;
            freq[nx] += ch;
            prev += aux[j];
        }
    }

    int mini = X, maxi = -1;
    for (int i = 0; i < X; i++) {
        if (!freq[i])
            continue;
        mini = min(mini, i);
        maxi = max(maxi, i);
    }
    printf("%d %d\n", maxi, mini);
}

