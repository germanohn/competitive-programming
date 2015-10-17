#include <bits/stdc++.h>

using namespace std;

int n, f, b, t;
long long int ans;

struct tipo {
    int floor, box;
};

tipo esc[1005], at[1005];

bool comp (tipo a, tipo b) {
    return a.floor < b.floor;
}

int main () {
    scanf ("%d", &t);
    for (int i = 0; i < t; i++) {
        ans = 0;
        scanf ("%d %d %d", &n, &f, &b);
        for (int j = 0; j < n; j++) {
            scanf ("%d %d", &esc[j].floor, &esc[j].box);
        }
        sort (esc, esc + n, comp);
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (esc[j].box == 0) {
                at[k].floor = esc[j].floor;
                at[k].box = esc[j].box;
                k++;
            }     
        }
        for (int j = n-1; j >= 0; j--) {
            if (esc[j].box == 1) {
                at[k].floor = esc[j].floor;
                at[k].box = esc[j].box;
                k++;
            }
        }
        /*for (int i = 0; i < n; i++) {
            printf ("floor %d box %d\n", at[i].floor, at[i].box);
        }*/
        int quant, quem, x, y;
        /* no caso de b/n nao ser divisao inteira, o numero sera o piso
        // entao quem entregara o ultimo livro tera que entregar quant
        // + 1 livros. se for divisao inteira entao tera que entregar quant
        // livros*/
        quant = b/n;
        quem = b%n - 1;
        if (quem < 0) quem = n-1;
        //printf ("quant %d quem %d\n", quant, quem);
        x = at[quem].box, y = at[quem].floor;
        if (b%n == 0) {
            if (x == 0)
                ans = y + quant*2*f - f;
            else 
                ans = f - y + quant*2*f;
        }
        else {
            if (x == 0) 
                ans = y + (quant+1)*2*f - f;
            else 
                ans = f - y + (quant+1)*2*f;
        }
        printf ("%lld\n", ans);        
    }
}
