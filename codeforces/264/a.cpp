#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

char s[MAX];
int v[MAX];

int main () {
    scanf(" %s", s);
    int l = 0, r = strlen(s) - 1;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == 'l') 
            v[r--] = i + 1;
        else 
            v[l++] = i + 1;
    }
    for (int i = 0; s[i] != 0; i++) 
        printf("%d\n", v[i]);
}

