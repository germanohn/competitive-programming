#include <bits/stdc++.h>

using namespace std;

int l, n;
map<string, string> m;
char a[105], b[105];
string s, ss;

bool consoa (char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
        return false;
    return true;
}

int main () {
    scanf ("%d %d", &l, &n);
    for (int i = 0; i < l; i++) {
        scanf ("%s %s", a, b);
        s = a; 
        ss = b;
        m[s] = ss; 
    }
    for (int i = 0; i < n; i++) {
        scanf (" %s", a);
        s = a;
        int k = strlen (a);
        if (m.find (s) != m.end ())
            cout << m[s] << endl;
        else if (k > 1) {
            if (s[k-1] == 'y' && consoa (s[k-2])) {
                a[k-1] = '\0';
                cout << a << "ies" << endl;
            }
            else if ((s[k-1] == 'h' && (s[k-2] == 'c' || s[k-2] == 's')) || s[k-1] == 's' || s[k-1] == 'x' || s[k-1] == 'o')
                cout << s << "es" << endl;
            else 
                cout << s << "s" << endl;
        }
        else {
            if (s[k-1] == 's' || s[k-1] == 'x' || s[k-1] == 'o')
                cout << s << "es" << endl;
            else
                cout << s << "s" << endl;
        }

    }
}
