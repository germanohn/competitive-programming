#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int a, b, s;
    scanf(" %d %d %d", &a, &b, &s);
     
    a = abs(a) + abs(b);
    if (a > s || (a < s && (s - a) % 2 == 1)) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
}

