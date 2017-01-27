#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 71234;

struct event {
    int uid, cid, adid, st, cf;
    event() {}
    event(int uid, int cid, int adid, int st, int cf) : uid(uid), cid(cid), adid(adid), st(st), cf(cf) {} 
} eve[N];


struct info {
    int uid, cid, ct, heur;
    info() {}
    info(int uid, int cid, int ct, int heur) : uid(uid), cid(cid), ct(ct), heur(heur) {}
    bool operator< (const info &o) const {
        if(ct != o.ct) return ct < o.ct;
        if(uid != o.uid) return uid < o.uid;
        return cid < o.cid;
    }
};

map<pii, set<info>> m;

struct ans {
    int uid, cid, ct, heur, adid, st, cf;
    ans() {}
    ans(int uid, int cid, int ct, int heur, int adid, int st, int cf) : uid(uid), cid(cid), ct(ct), heur(heur), adid(adid), st(st), cf(cf) {}
    bool operator< (const ans &o) const {
        if(heur != o.heur) return heur < o.heur;
        if(uid != o.uid) return uid < o.uid;
        if(cid != o.cid) return cid < o.cid;
        if(ct != o.ct) return ct < o.ct;
        if(adid != o.adid) return adid < o.adid;
        if(st != o.st) return st < o.st;
        return cf < o.cf;
    }
};

int main () {
    int intc, evec;
    scanf("%d %d", &intc, &evec);
    for(int i = 0; i < intc; i++) {
        int uid, cid, ct, heur;
        scanf("%d %d %d %d", &uid, &cid, &ct, &heur);
        pii key = pii(uid, cid);
        info value = info(uid, cid, ct, heur);
        m[key].insert(value);
    }
    for(int i = 0; i < evec; i++) {
        int uid, cid, adid, st, cf;
        scanf("%d %d %d %d %d",&uid, &cid, &adid, &st, &cf);
        eve[i] = event(uid, cid, adid, st, cf);
    }
    vector<ans> v;
    for(int i = 0; i < evec; i++) {
        pii key = pii(eve[i].uid, eve[i].cid);   
        set<info> &s = m[key];
        set<info>::iterator it = s.lower_bound(info(0, 0, eve[i].st, 0));
        if(it != s.begin()) {
            it--;
            info match = *it;
            v.pb(ans(eve[i].uid, eve[i].cid, match.ct, match.heur, eve[i].adid, eve[i].st, eve[i].cf));
        }
    }
    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for(ans x : v) printf("%d %d %d %d %d %d %d\n", x.uid, x.cid, x.ct, x.heur, x.adid, x.st, x.cf);
}

