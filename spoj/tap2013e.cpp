#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int q;
int pot[25];
char s[N], t[N];
set<string> st;

int main() {
        pot[1] = 2;
        for (int i = 2; i <= 20; i++) 
                pot[i] = pot[i - 1] * 2;
        scanf(" %d", &q);
        while (q--) {
                scanf(" %s", s);        
                st.clear();
                for (int i = 1; i <= 20; i++) {
                        st.clear();
                        int len = strlen(s);
                        for (int j = 0; j < i; j++) 
                                t[j] = s[j];
                        t[i] = '\0';
                        for (int j = 0; j + i - 1 < len; j++) {
                                t[j + i - 1] = s[j + i - 1];
                                t[j + i] = '\0';
                                st.insert(t + j);
                        } 
                        if (st.size() < pot[i]) {
                                printf("%d\n", i);
                                break;
                        }
                }
        }
}
