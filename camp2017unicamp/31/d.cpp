#include <bits/stdc++.h>
#define hash huehua
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef unsigned long long hash;
typedef pair<int, int> pii;

const int N = 51234;
char s[N], t[N], sr[N];

hash X = 33;
hash x[N], h[N], hr[N];

hash val(char c) {
    int k;
    if(isdigit(c)) k = 52 + c - '0';
    else if(isupper(c)) k = c - 'A' + 26;
    else k = c - 'a';
    return k + 1;
}

hash calc(int i, int j) {
    if(i > j) return 0;
    return h[j+1] - h[i] * x[j-i+1];
}

hash calcr(int i, int j) {
    if(i > j) return 0;
    return hr[j+1] - hr[i] * x[j-i+1];
}

int main () {
    scanf(" %s %s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    if(n != m) {
        puts("No");
        return 0;
    }
    if(strcmp(s, t) == 0) {
        puts("Yes\n0");
        return 0;
    }
    x[0] = 1;
    hash ht = 0;
    for(int i = n-1; i >= 0; i--) sr[n-i-1] = s[i];
    for(int i = 0; s[i]; i++) {
        x[i+1] = x[i] * X;
        h[i+1] = h[i] * X + val(s[i]);
        ht = ht * X + val(t[i]);
        hr[i+1] = hr[i] * X + val(sr[i]);
    }
    for(int i = 0; i < n; i++) {
        if(calc(i+1, n-1) * x[i+1] + calcr(n-i-1, n-1) == ht) {
            puts("Yes");
            printf("%d\n", i+1);
            return 0;
        } 
    }
    puts("No");
}

