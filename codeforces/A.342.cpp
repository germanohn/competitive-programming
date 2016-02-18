#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll a, b, c, n, ans;

int main () {
    cin >> n >> a >> b >> c;
    if (a <= b - c) cout << n/a << endl;
    else if (a >= b) {
       ll k = 0;
       if (n >= b) {
           //quero saber o k tal que n - k(b-c) < b
           k = (n - b)/(b - c) + 1;
           n -= k*(b - c);
       }
       //sempre é otimo pegar o ultimo de b
       k += n/b;
       cout << k << endl; 
    }
    else {
       ll k = 0;
       if (n >= b) {
           k = (n - b)/(b - c) + 1;
           n -= k*(b - c);
       }
       //sempre é otimo pegar o ultimo de a
       k += n/a;
       cout << k << endl; 
    }
}
