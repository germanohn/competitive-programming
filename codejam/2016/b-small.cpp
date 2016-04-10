#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t;
string s;
map<string, int> d;

bool ok (string str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '+') 
            return false;
    }
    return true;
}

string flip (string str, int p1, int p2) {
    while (p1 < p2) {
        if (str[p1] == '-') {
            str[p1] = '+';
        } else {
            str[p1] = '-';
        }
        if (str[p2] == '+') {
            str[p2] = '-';
        } else {
            str[p2] = '+';
        }
        char tmp = str[p1];
        str[p1] = str[p2];
        str[p2] = tmp;
        p1++, p2--;
    }
    if (p1 == p2) {
        if (str[p1] == '-')
            str[p1] = '+';
        else 
            str[p1] = '-';
    }
    return str;
}

int bfs () {
    queue<string> q;
    q.push (s);
    d[s] = 0;
    while (!q.empty ()) {
        string str = q.front ();
        q.pop ();
        if (ok (str)) 
            return d[str];
        for (int i = 0; str[i] != '\0'; i++) {
            string s1 = flip (str, 0, i);
            if (d[s1] == 0) {
                q.push (s1);
                d[s1] = d[str]+1;
            }
        } 
    }
}

int main () {
    scanf ("%d", &t);
    int cont = 1;
    while (t--) {
        d.clear ();
        cin >> s;
        int ans = bfs ();
        printf ("Case #%d: %d\n", cont++, ans);
    }
}

