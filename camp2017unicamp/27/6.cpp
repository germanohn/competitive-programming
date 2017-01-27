#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define OPEN 0
#define CLOSE 1
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1123456;

char s[N];
int f[4], st[N], ps, cor[N];
int abre[] = {'(', '[', '{', '<'};
int fecha[] = {')', ']', '}', '>'};
multiset<char> ms[N];

int open(char c) {
    return c == '(' || c == '[' || c == '{' || c == '<';
}

int conv(char c) {
    if(c == '(' || c == ')') return 0;
    if(c == '[' || c == ']') return 1;
    if(c == '<' || c == '>') return 2;
    if(c == '{' || c == '}') return 3;
    return 99;
}

bool match(int i, int j) {
    multiset<char>::iterator ii, jj;
    for(int k = 0; k < 4; k++) {
        ii = ms[cor[i]].find(abre[k]);
        jj = ms[cor[j]].find(fecha[k]);
        if(ii != ms[cor[i]].end() && jj != ms[cor[j]].end()) {
            ms[cor[i]].erase(ii);
            ms[cor[j]].erase(jj);
            return true;
        }
    }
    return false;
}

bool comp(pii a, pii b) {
    return a.second-a.first < b.second-b.first;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d",&n);
    while(n--) {
        getchar();
        scanf("%[^\n]", s);
        bool valid = true;
        for(int i = 0; s[i]; i++) { 
            ms[i].clear();
        }
        int last = -1;
        int cs = -1;
        vector<pii> o;
        ps = 0;
        for(int i = 0; s[i]; i++) {
            int now;
            if(open(s[i])) now = OPEN; 
            else now = CLOSE;
            if(now != last) cs++;
            ms[cs].insert(s[i]);
            cor[i] = cs;

            if(open(s[i])) st[ps++] = i;
            else {
                if(ps) {
                    int j = st[--ps];
                    o.pb(pii(j, i));
                } else valid = false;
            }
            last = now;
        }
        if(ps) valid = false;
        if(valid) {
            sort(o.begin(), o.end(), comp);
            for(pii p : o) {
                if(!match(p.first, p.second)) {
                    valid = false; 
                    break;
                }
            }
        }
        if(valid) puts("T");
        else puts("NIL");
    }
}

