#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    char A[10][10];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &A[i][j]);
        }
    }
    bool ans = true;
    for (int i = 0; ans && i < 8; i++) {
        bool ok = true;
        char a = 'A';
        for (int j = 0; ok && j < 8; j++) {
            if (A[i][j] == a) ok = false;
            a = A[i][j];
        }
        if (!ok) ans = false;
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}

