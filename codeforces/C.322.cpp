#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

/*struct skill {
    int num;
    int dif;
};*/

//skill v[100005];

typedef pair<int, int> pii;

int n, k, aux;

vector<pii> v;

bool comp (pii a, pii b) {
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main () {
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &aux);
        v.pb (mp (aux, 10 - (aux % 10))); 
    }

    sort (v.begin (), v.end (), comp);
    int i = 0;
    while (k > 0) {
        if (i == 0) {
            sort (v.begin (), v.end (), comp);
            if (v[0].first == 100)
                break;
        }   
 
        if (v[i].first != 100) {
        
            if (v[i].second > k) break;
        
            v[i].first += v[i].second;
            k -= v[i].second;
            v[i].second = 10;
        }
        i = (i + 1) % n;
   } 
    int ans = 0;
    for (int j = 0; j < n; j++) 
        ans += v[j].first/10;
    printf ("%d\n", ans);

}
