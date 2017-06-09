#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t;

int main () {   
    scanf(" %d", &t);
    while (t--) {
        int a;
        scanf(" %d", &a);
        if (360 % (180 - a) == 0) 
            printf("YES\n");
        else printf("NO\n");
    }
}

