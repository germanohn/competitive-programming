#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2000005;

int a, m;
bool seen[MAX];

int main () {
    scanf(" %d %d", &a, &m);
    while (!seen[a] && a % m != 0) {
        seen[a] = true;
        a += (a % m);
    }
    if (a % m == 0) printf("Yes\n");
    else printf("No\n");
}

