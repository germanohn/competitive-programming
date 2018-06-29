#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 55;

void reduce_string(char *s) {
    int l = 0;
    for (int i = 1; s[i] != 0; i++) {
        if (s[i] != s[l]) {
            s[l + 1] = s[i];
            l++;
        }
    }
    s[l + 1] = 0;
}

int main() {
    int tests;
    char s[N], t[N];
    scanf(" %d", &tests);
    while (tests--) {
        scanf(" %s %s", s, t);
        reduce_string(s);
        reduce_string(t);
        if (strcmp(s, t) != 0) 
            printf("No\n");
        else 
            printf("Yes\n");
    }
}

