#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n, m, q_p, q_i;
int v[MAX], ans[MAX];
priority_queue<pii> even, odd;
set<int> ans_even, ans_odd, rta;
map<int, int> freq;
vector<int> falta;

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        if (v[i] % 2 == 0) freq[v[i]]++, ans_even.insert(v[i]);
        else freq[v[i]]++, ans_odd.insert(v[i]);
    }
    for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++) {
        if (it->ff % 2 == 0) even.push(pii(it->ss, it->ff)), q_p += it->ss;
        else odd.push(pii(it->ss, it->ff)), q_i += it->ss;
    }
    int dif_even, dif_odd;
    dif_even = dif_odd = 0;
    for (int i = 1; i <= m; i++) {
        if (i % 2 == 1) {
            if (ans_odd.find(i) == ans_odd.end())
                dif_odd++;
        } else {
            if (ans_even.find(i) == ans_even.end())
                dif_even++;
        }
    }
    dif_odd += ans_odd.size();
    dif_even += ans_even.size();
    if (dif_odd < n/2 || dif_even < n/2) {
        printf("-1\n");
        return 0;
    }
    // agora tenho resposta
    int want_e, want_o;
    want_e = 2, want_o = 1;
    if (q_p > q_i) {
        while (q_p > n/2) {
            printf("q_p %d tem mais par que impar\n", q_p);
            pii e = even.top();
            //printf("topo par %d\n", e.ss);
            even.pop();
            e.ff--, q_p--;
            if (e.ff != 0) even.push(e);
            else ans_even.erase(e.ss);
            for (; want_o <= m; want_o += 2) {
                if (ans_odd.find(want_o) == ans_odd.end()) {
                    q_i++;
              //      printf("coloquei %d nos impares\n", want_o);
                    ans_odd.insert(want_o);
                    odd.push(pii(1, want_o));
                }
            }
        }
    } else if (q_p < q_i) {
        while (q_i > n/2) {
            printf("q_i %d tem mais impar do que par\n", q_i);
            pii o = odd.top();
            //printf("topo impar %d\n", o.ss);
            odd.pop();
            o.ff--, q_i--;
            if (o.ff != 0) odd.push(o);
            else ans_odd.erase(o.ss);
            for (; want_e <= m; want_e += 2) {
                if (ans_even.find(want_e) == ans_even.end()) {
                    q_p++;
              //      printf("coloquei %d nos pares\n", want_e);
                    ans_even.insert(want_e);
                    even.push(pii(1, want_e));
                }
            }
        }
    } 

    while (even.top().ff > 1) {
        pii e = even.top();
        printf("%d tem %d vezes ainda\n", e.ss, e.ff);
        even.pop();
        e.ff--;
        if (e.ff != 0) even.push(e);
        else ans_even.erase(e.ss);
        for (; want_e <= m; want_e += 2) {
            if (ans_even.find(want_e) == ans_even.end()) {
                ans_even.insert(want_e);
                even.push(pii(1, want_e));
            }
        }
    }
    while (odd.top().ff > 1) {
        pii o = odd.top();
        printf("%d tem %d vezes ainda\n", o.ss, o.ff);
        odd.pop();
        o.ff--;
        if (o.ff != 0) odd.push(o);
        else ans_odd.erase(o.ss);
        for (; want_o <= m; want_o += 2) {
            if (ans_odd.find(want_o) == ans_odd.end()) {
                ans_odd.insert(want_o);
                odd.push(pii(1, want_o));
            }
        }
    }

    int ch = 0;
    for (int i = 0; i < n; i++) {
        if (rta.find(v[i]) != rta.end()) {
            ch++;
            continue;
        }
        if (v[i] % 2 == 0) {
            if (ans_even.find(v[i]) != ans_even.end()) 
                ans[i] = v[i], rta.insert(v[i]);
            else 
                ch++;
        } else {
            if (ans_odd.find(v[i]) != ans_odd.end())
                ans[i] = v[i], rta.insert(v[i]);
            else 
                ch++;
        }
    }

    for (set<int>::iterator x = ans_even.begin(); x != ans_even.end(); x++) {
        if (rta.find(*x) == rta.end())
            falta.pb(*x);
    }
    for (set<int>::iterator x = ans_odd.begin(); x != ans_odd.end(); x++) {
        if (rta.find(*x) == rta.end())
            falta.pb(*x);
    }
    int p = 0;
    printf("%d\n", ch);
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) printf("%d ", falta[p++]);
        else printf("%d ", ans[i]);
    }
    printf("\n");
}

