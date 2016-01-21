#include <bits/stdc++.h>
using namespace std;

int main () {
    cout << "0 " << "0" << endl;
    cout.flush ();
    int n;
    cin >> n;
    int  k;
    int l = 0, h = 1000000000, m;
    while (h - l > 1) {
         m = (l+h)/2;
         cout << m << " 0" << endl;
         cout.flush ();
         cin >> n;
         cout << m-1 << " 0" << endl;
         cout.flush ();
         cin >> k;
         if (n && k) h = m-1;
         else if (n && !k) l = m;
         else if (!n && k) h = m-1;
         else l = m-1;
    }
    int x = l;
    l = 0, h = 1000000000;
    while (h - l > 1) {
        m = (l+h)/2;
        cout << x << " " << m << endl;
        cout.flush ();
        cin >> n; 
        cout << x << " " << m-1 << endl;
        cout.flush ();
        cin >> k;
        if (k) h = m-1;
        else l = m;
    }
    int y = l;
    cout << "A " << x << " " << y << endl;
}
