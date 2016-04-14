#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 212345;

int n, m, pai[30];
bool seen[30];
char s[MAX], a, b;

int find (int a) {
    if (a == pai[a]) return a;
    return pai[a] = find (pai[a]);
}

int main () {
    scanf ("%d %d %s", &n, &m, s);
    for (int i = 0; i < 26; i++) 
        pai[i] = i;
    for (int i = 0; i < m; i++) {
        scanf (" %c %c", &a, &b);
        if (!seen[a-'a'])
            pai[a-'a'] = pai[b-'a'];
        seen[a-'a'] = true;
        seen[b-'a'] = false;
    }
    for (int i = 0; i < 26; i++) {
        if (pai[i] != i) {
            printf ("i %d pai[i] %d letra %c\n", i, pai[i], i+'a');
        }
    }
    for (int i = 0; i < 26; i++) {
        if (pai[i] != i) {
            int num = find (i);
            printf ("letra %c pai %c\n", i+'a', num+'a');
            for (int j = 0; s[j] != 0; j++) {
                int l = s[j]-'a';
                if (l == i)
                    s[j] = num+'a';
            }
        }
    }
    printf ("%s\n", s);
}

