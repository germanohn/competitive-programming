#include<bits/stdc++.h>
using namespace std;

const int MAX = 200005;

string s[MAX];
set<string> msg;

int main() {
    int n;
    scanf(" %d", &n);

    for (int i = 0; i < n; i++) 
        cin >> s[i];

    for (int i = n - 1; i >= 0; i--) {
        if (msg.find(s[i]) == msg.end()) { 
            cout << s[i] << endl;
            msg.insert(s[i]);
        }
    }
}
