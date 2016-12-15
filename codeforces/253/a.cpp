#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n, m;
    FILE * in, * out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    fscanf(in, " %d %d", &n, &m);
    if (n < m) {
        for (int i = 0; i < 2*n; i += 2) 
            fprintf(out, "GB");
        for (int i = 0; i < m - n; i++) 
            fprintf(out, "G");
        fprintf(out, "\n");
    } else {
        for (int i = 0; i < 2*m; i += 2) 
            fprintf(out, "BG");
        for (int i = 0; i < n - m; i++) 
            fprintf(out, "B");
        fprintf(out, "\n");
    }
}

