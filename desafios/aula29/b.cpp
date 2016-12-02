#include<bits/stdc++.h>
using namespace std;

int v[5] = {2, 3, 5, 7};
int d[20] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool test(int t) {
    char s[10];
    printf("%d\n", t);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'y') return true;
    else return false;
}

int main() {
    bool prime = true;
    for (int i = 0; i < 4; i++) {
        if (test(v[i])) {
            if (test(v[i]*v[i])) {
                prime = false;
            } else {
                for (int j = i + 1; prime && j < 4; j++) {
                    if (test(v[j]))
                        prime = false;
                }
                for (int j = 0; prime && j < 11; j++) {
                    if (test(d[j]))
                        prime = false;
                }
            }
            break;
        }
    }

    if (prime) printf("prime\n");
    else printf("composite\n");
}
