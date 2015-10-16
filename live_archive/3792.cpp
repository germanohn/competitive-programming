#include <bits/stdc++.h>

using namespace std;

char w[15], x[15], y[15], ans;

bool ver (int i) {
    for (int i = i + 1; w[i] != '\0' && w[i] != '?'; i++) {
        if (w[i] - '0' > x[i] - '0')
            return 1;
        else if (w[i] - '0' < x[i] - '0') {
            return -1;
        }
    }
    if (w[i] == '?')
        return 2;
    else 
        return 10;
}

int main () {
    while (scanf ("%s %s", &w, &x); && w[0] != '#') {
        /*for (int i = 0; w[i] != '\0'; i++) {
            if (w[i] != '?') 
                y[i] = w[i];
            else
                y[i] = x[i];
        }*/
        bool ffint = true, ffnum = true;
        int maior = 0;
        for (int i = 0; w[i] != '\0'; i++) {
            if (w[i] != '?' && ffnum) {
                if (w[i] - '0' < x[i] - '0')
                    maior = -1;
                else if (w[i] == x[i])
                    maior = 0;
                else
                    maior = 1;
                fnum = false;
            }
            else if (w[i] != '?' && maior == 0) {
                if (w[i] - '0' < x[i] - '0')
                    maior = -1;
                else if (w[i] == x[i])
                    maior = 0;
                else
                    maior = 1;
            }
            else if (w[i] == '?' && maior == 1) { 
                if (ffint) {
                    ans = 10 - (x[i] - '0');
                    ffint = false;
                }
                else {
                    ans *= 10 - (x[i] - '0');
                }
            }
            else if (w[i] == '?' && maior == 0) { 
                int maxi;
                maxi = ver (i);
                if (ffint) {
                    if (maxi == 1) {  
                        ans = 10 - (x[i] - '0');
                    }
                    else if (maxi == 10) {
                        ans = 10 - (x[i] - '0') - 1;   
                    }
                    else if (maxi == 2) {
                        ans = 10 - (x[i] - '0'); 
                    }
                    ffint = false;
                }
                else {
                    ans *= 10 - (x[i] - '0') + 1;
                }
            }
        }
    }
}
