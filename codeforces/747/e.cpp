#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

char s[MAX];
pair<char *, int> pilha[MAX];
vector<char *> ans[MAX];

int main () {
    scanf(" %s", s);
    char * ps;
    ps = strtok(s, ",");
    int p = 0, level = 0, max_level = 0;
    while (ps != NULL) {
        max_level = max(max_level, level);
        //printf("%s p %d level %d\n", ps, p, level);
        char * num;
        num = strtok(NULL, ",");
        ans[level].pb(ps);
        pilha[p].ff = ps;
        int a = atoi(num);
        pilha[p].ss = a;
        while (pilha[p].ss == 0) {
            p--, level--;
            pilha[p].ss--;
        }
        p++, level++;
        ps = strtok(NULL, ",");
    }
    printf("%d\n", max_level + 1);
    for (int i = 0; i <= max_level; i++) {
        for (auto str : ans[i]) 
            printf("%s ", str);
        printf("\n");
    }
}

