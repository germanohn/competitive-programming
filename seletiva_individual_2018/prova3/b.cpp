#include<bits/stdc++.h>
using namespace std;

const int E = 26;
const int N = 1e5 + 5;

int freq[E][N];

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int n, d; 
        char a[N], b[N];
        scanf(" %d %d %s %s", &n, &d, a, b);
        for (int i = 0; i < E; i++) 
            for (int j = 0; j < n; j++)
                freq[i][j] = 0;
        for (int i = 0; b[i] != 0; i++) {
            int letter = b[i] - 'a';
            freq[letter][i % d]++;
        }
        bool ok = true;
        for (int i = 0; a[i] != 0 && ok; i++) {
            int letter = a[i] - 'a';
            ok = freq[letter][i % d];
            freq[letter][i % d]--;
        }
        if (ok) 
            printf("Yes\n");
        else 
            printf("No\n");
    }
}

