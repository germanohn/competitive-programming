#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1000005;

pii tree[MAX];
set<int> appear;

void post_order(int no) {
    if (tree[no].l != -1) post_order(tree[no].l);
    if (tree[no].r != -1) post_order(tree[no].r);
    printf("%d\n", no);    
}

int main() {
    int no, ant, raiz;
    scanf(" %d", &ant);
    memset(tree, -1, sizeof tree);
    raiz = ant;
    appear.insert(ant);
    while (scanf(" %d", &no) != EOF) {
        if (no < ant) {
            tree[ant].l = no;
        } else { 
            int pai = *prev(appear.lower_bound(no));
            tree[pai].r = no;
        }
        ant = no;
        appear.insert(no);
    }    

    post_order(raiz);
}
