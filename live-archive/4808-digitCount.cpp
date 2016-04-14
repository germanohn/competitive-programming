#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b, v[15], x;
char str[10];
ll me[35][35][2][2];

// Importante: estamos construindo o numero do digito mais significativo ao menos
// i é o digito que eu estou olhando na string str
// s é a soma de digitos x ate str
// pre é true se o que eu construi desde o digito mais significativo ate agora é igual ao b
// f é true se eu ja coloquei um numero diferente de 0
ll dp (int i, int s, bool pre, bool f) {
    //esse str[i] == 0 é o mesmo que str[i] == '\0'
    if (str[i] == 0) return s;
    ll &m = me[i][s][pre][f];
    if (m != -1) return m;
    m = 0;
    for (int j = 0; j <= 9; j++) {
        if (pre && j > str[i]-'0') break; 
        // ou pre é verdadeiro e j <= str[i] ou !pre e entao eu posso colocar qualquer j
        if (j != 0) f = true;
        m += dp (i+1, s + ((j==x)&(f)), pre && j== str[i]-'0', f);
    }
    return m;
}

int main () {
    while (scanf ("%d %d", &a, &b) && a != 0) {
        sprintf (str, "%d", b);
        for (int i = 0; i < 10; i++) {
            memset (me, -1, sizeof (me));
            x = i;
            v[i] = dp (0, 0, true, false);
        }
        sprintf(str, "%d", a-1);
        for(int i=0; i<10; i++) {
            memset (me, -1, sizeof (me));
            x = i;
            v[i] -= dp (0, 0, true, false);
        }
        for (int i = 0; i<=9; i++) {
            printf ("%d%c", v[i], i==9 ? '\n' : ' ');
        }
    }
}
