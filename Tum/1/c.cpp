#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {
    //ios_base:sync_with_stdio(false);
    int t;
    int cont = 1;
    scanf(" %d", &t);
    while (t--) {
        int n;
        string s;
        scanf(" %d ", &n);
        printf("Case #%d:\n", cont++);
        for (int i = 0; i < n; i++) {
            getline(cin, s);

            int len = s.length();
            int j = 0;
            while (s[j] != 0) {
                if (s[j] == 'e') {
                    if (j + 5 <= len && (s.substr(j, 5) == "entin" || s.substr(j, 5) == "enten")) {
                        printf("ierende");
                        j += 5; 
                    } else if (j + 3 <= len && s.substr(j, 3) == "ent") {
                        printf("ierender");
                        j += 3;
                    } else {
                        printf("e");
                        j++;
                    }
                } else {
                    printf("%c", s[j]);
                    j++;
                }
            }
            printf("\n");
        } 
    }
}

