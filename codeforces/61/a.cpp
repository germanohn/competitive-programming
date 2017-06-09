#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char a[105], b[105];

int main () {
    scanf(" %s %s", a, b);
    for (int i = 0; a[i] != 0; i++) {
        if (a[i] != b[i]) 
            printf("1");
        else printf("0");
    }
    printf("\n");
}

