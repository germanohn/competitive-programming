#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 6;

int freq[N];
char s[N];
char t[2][3] = {'R', 'B', 'L', 'S', 'K', 'H'};

int id(char c) {
    if (c == 'R') return 0;
    else if (c == 'B') return 1;
    else return 2;
}

int main () {
    scanf(" %s", s);

    int len = strlen(s);
    int inc = 1;
    for (int i = 0; s[i] != 0; i += inc) {
        int cont = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = i; k < min(i + 3, len); k++) {
                if (s[k] == t[0][j]) {
                    cont++;
                    break;
                }
            }
        }

        if (cont == 3) { 
            printf("C");
            inc = 3;
        } else {
            printf("%c", t[1][id(s[i])]);
            inc = 1;
        }
    }
    printf("\n");
}

