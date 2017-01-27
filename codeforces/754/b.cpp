#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char gr[5][5];

int main () {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf(" %c", &gr[i][j]);
        }
    }
    bool win = false;
    for (int i = 0; !win && i < 4; i++) {
        for (int j = 0; !win && j < 4; j++) {
            int cont_x = 0, cont_pto = 0;
            for (int col = j; col < 4 && col - j < 3; col++) {
                if (gr[i][col] == 'x') cont_x++;
                else if (gr[i][col] == '.') cont_pto++;
            } 
            if (cont_x == 3 || (cont_x == 2 && cont_pto == 1)) win = true;
            cont_x = cont_pto = 0;
            for (int row = i; i < 4 && row - i < 3; row++) {
                if (gr[row][j] == 'x') cont_x++;
                else if (gr[row][j] == '.') cont_pto++;
            }
            if (cont_x == 3 || (cont_x == 2 && cont_pto == 1)) win = true;
            cont_x = cont_pto = 0;
            for (int up = 0; up < 3; up++) {
                if (i + up >= 4 || j + up >= 4) 
                    break;
                if (gr[i + up][j + up] == 'x') cont_x++;
                else if (gr[i + up][j + up] == '.') cont_pto++;
            }
            if (cont_x == 3 || (cont_x == 2 && cont_pto == 1)) win = true;
            cont_x = cont_pto = 0;
            for (int up = 0; up < 3; up++) {
                if (i + up >= 4 || j - up < 0) 
                    break;
                if (gr[i + up][j - up] == 'x') cont_x++;
                else if (gr[i + up][j - up] == '.') cont_pto++;
            }
            if (cont_x == 3 || (cont_x == 2 && cont_pto == 1)) win = true;
        }
    }
    if (win) printf("YES\n");
    else printf("NO\n");
}

