#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define list soares
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1003;

char s[N][N];

void list(int i, int j, int d){
    if(s[i][d-1] == '*') puts("<ul>");
    else puts("<ol>");
    int f = i;
    for(int g = f+1; g <= j; g++) {
        if(s[f][d] != '*' && s[f][d] != '#') {
            puts("<li>");
            puts(s[f]+d);
            puts("</li>");
            f = g;
        } else {
            if(s[f][d] != s[g][d]) {
                puts("<li>");
                if(g-f >= 2) list(f, g-1, d+1);
                else {
                    puts(s[f]+d);
                }
                f = g;
                puts("</li>");
            }
        }
    }
    int g = j+1;
    puts("<li>");
    if(g - f >= 2) list(f, g-1, d+1);
    else {
        puts(s[f]+d);
    }
    puts("</li>");

    if(s[i][d-1] == '*') puts("</ul>");
    else puts("</ol>");
}

int main () {
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i = 0;
    int j = 0;
    while(scanf(" %s", s[j]) != EOF) {
        if(s[i][0] != s[j][0]) {
            if(j - i >= 2) list(i, j-1, 1);
            else puts(s[i]);
            i = j;
        }
        if(s[i][0] != '*' && s[i][0] != '#') {
            puts(s[i]);
            i = j+1;
        }
        j++;
    } 
    if(j - i >= 2) list(i, j-1, 1);
    else if(s[i][0] == '#' || s[i][0] == '*') puts(s[i]);
}

