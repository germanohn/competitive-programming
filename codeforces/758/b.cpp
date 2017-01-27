#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

char s2[5] = "RBYG";
char s1[MAX];
int pos[256];
int ans[256];
vector<int> color[256];

int main () {
    scanf(" %s", s1);
    for (int i = 0; s1[i] != 0; i++) {
        if (s1[i] != '!')
            color[s1[i]].pb(i);
    }
    int len = strlen(s1);
    for (int j = 0; j < 4; j++) 
        color[s2[j]].pb(len + 1);
    for (int i = 0; i < len - 4; i++) {
        if (s1[i] == '!') {
            int nx = len + 1, ind;
            for (int j = 0; j < 4; j++) {
                if (color[s2[j]][pos[s2[j]]] < nx) 
                    ind = j, nx = color[s2[j]][pos[s2[j]]];
            }
            pos[s2[ind]]++;
            ans[s2[ind]]++;
            s1[i] = s2[ind];
        }
    }
    for (int i = len - 4; i < len; i++) {
        if (s1[i] == '!')

    }
    for (int i = 0; i < 4; i++) {
        printf("%d ", ans[s2[i]]);
    }
    printf("\n");
}

