#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

char s[MAX];

int main () {
    scanf (" %s", s);
    int equal = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i+1] != 0) {
            if (equal == 0) {
                if (s[i] == s[i+1])
                    equal++;
            } else if (equal == 1) {
                for (int l = 0; l <= 2; l++) {
                    if (l != s[i-1]-'a' && l != s[i+1]-'a') {
                        s[i] = l+'a';
                        break;
                    }
                }
                equal = 0;
                //cont++;
            }
        } else {
            if (equal == 1) {
                for (int l = 0; l <= 2; l++) {
                    if (l != s[i-1]-'a' && l != s[i+1]-'a') {
                        s[i] = l+'a';
                        break;
                    }
                }
             //   cont++;
            }
        }
    }    
    printf ("%s\n", s);
}

