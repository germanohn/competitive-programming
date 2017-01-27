#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

char s[MAX];
char one[20] = {'B', 'l', 'b', 's', 'r'};
char two[20] = {'u', 'a'};
int freq[300];

int main () {
    scanf(" %s", s);
    for (int i = 0; s[i] != 0; i++) 
        freq[s[i]]++;
    int ans = INT_MAX;
    for (int i = 0; i < 5; i++) 
        ans = min(ans, freq[one[i]]); 
    for (int i = 0; i < 2; i++) {
        ans = min(ans, freq[two[i]]/2);
    }
    printf("%d\n", ans);
}

