#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

char s[MAX];
int freq[126];

int main () {
    scanf(" %s", s);
    for (int i = 0; s[i] != 0; i++) 
        freq[s[i]]++;
    int cont = 0;
    for (int i = 0; i < 126; i++) {
        if (freq[i] % 2 == 1) 
            cont++;
    }
    if (cont == 0 || cont % 2 == 1) 
        printf("First\n");
    else 
        printf("Second\n");
}

