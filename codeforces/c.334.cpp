#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int n, tam; 
char str[MAX];



int main () {
    scanf ("%d %s", &n, str);
    int empty = 0, size = 1;
    int p = str[0];
    for (int i = 1; i < n; i++) {
        if (str[i] != p) {
            if (p == '1') p = '0';
            else p = '1';
            size++;
        } 
        else 
            empty++;
    } 
    if (size == n) printf ("%d\n", size);
    else {
        printf ("%d\n", size + 1 + (empty > 1));
    }
} 
