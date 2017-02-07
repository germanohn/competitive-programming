#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct node {
    map<char, node*> nx; 
    bool end;
    node() : end(false) {}
};
typedef node * trie;

trie root;

char s[333];
bool add() {
    trie t = root;
    for(int i = 0; s[i]; i++) {
        if(!t->nx[s[i]]){
            trie son = new node();
            t->nx[s[i]] = son;
        }
        t = t->nx[s[i]];
        if(!s[i+1]) {
            if(t->end) return false;
            t->end = true;
        } 
    }
    return true;
}

int main () {
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    root = new node();
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    ll x = 1;
    sprintf(s, "1");
    add();
    for(int i = 1; i <= 1000000; i++) {
        x = (a * x + x % b) % c;
        sprintf(s, "%lld", x);
        if(!add()){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
}
