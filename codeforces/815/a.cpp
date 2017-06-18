#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool isPalin(int hour, int minu) {
    int b = hour % 10;
    hour /= 10;
    int a = hour % 10;

    int d = minu % 10;
    minu /= 10;
    int c = minu % 10;

    if (a == d && b == c) return true;
    return false;
}

int main () {
    char s[6];
    scanf(" %s", s);
    int hour = (s[0] - '0') * 10 + (s[1] - '0');
    int minu = (s[3] - '0') * 10 + (s[4] - '0');

    int cont = 0;
    while (!isPalin(hour, minu)) {
        if (minu < 59) 
            minu++;
        else {
            if (hour < 23)
                hour++;
            else
                hour = 0;
            minu = 0;
        }
        cont++;
    }

    printf("%d\n", cont);
}

