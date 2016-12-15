#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, a, b;
char s[MAX];

int main () {
    scanf(" %d %d %d %s", &n, &a, &b, s);
    printf("%d\n", s[a] != s[b]);
}

