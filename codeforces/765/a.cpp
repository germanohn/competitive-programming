#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
char s[10];

int main () {
    scanf(" %d %s", &n, s);
    for (int i = 0; i < n; i++) {
        scanf(" %s", s);
    }
    if (n % 2 == 1) printf("contest\n");
    else printf("home\n");
}

