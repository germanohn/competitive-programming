#include <bits/stdc++.h>
#define MAX 1003
#define INF 999999999.0
#define pb push_back
#define mp make_pair
#define weight first
#define vert second
using namespace std;
typedef pair<double,int> pii;

int n, m, t, p, dd;
int timer;
double d[MAX];
vector<pii> adj[MAX];
vector<int> adj2[MAX];
map<string,int> name;

double calc(){
    double peso;
    double pp = (double) p / 100.0;
    double lhs = t * (1.0-pp);
    double rhs = (t + (dd +1.0)/2.0) * pp;

    peso = lhs + rhs;
    return peso;
}

double div(double a){
    while(a >= 60)
        a -= 60;
    return a;
}

double solve (int src, int end){
    set<pii> pq;
    d[src] = timer;
    pq.insert(pii(timer,src));
    while(pq.size()){
        int x = pq.begin()->vert;
        pq.erase(pq.begin());
        if(x == end) return d[x]-timer;   
        for(int i = 0; i < adj[x].size(); i++){
            pii nxt = adj[x][i];
            double foo = div(d[x]);
            double atraso;
            if(foo <= adj2[x][nxt.vert]) atraso = adj2[x][nxt.vert] - foo;
            else atraso = 60-foo+adj2[x][nxt.vert];
            if(d[nxt.vert] > d[x] + nxt.weight + atraso){
                d[nxt.vert] = d[x] + nxt.weight + atraso;
                pq.insert(pii(d[nxt.vert], nxt.vert));
            }
        }
    }
    return INF;
}

int main(){
    int tc;
    double ans;
    string c1, c2, st, end;   
    char bla[25];
    scanf("%d", &tc);
    while(tc--){
        name.clear();
        scanf(" %s",bla);
        st = bla;
        scanf(" %s",bla);
        end = bla;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            adj[i].clear();
            adj2[i].clear();
        }
        int cont = 0;
        for(int i = 0; i < n; i++){
            scanf(" %s",bla);
            c1 = bla;
            scanf(" %s",bla);
            c2 = bla;
            scanf("%d %d %d %d", &m, &t, &p, &dd); 
            double peso = calc();
            cout << c1 << "->" << c2 << " " << peso << endl;
            if (name.find(c1) == name.end())
                name[c1] = cont++;
            if (name.find(c2) == name.end())
                name[c2] = cont++;
            adj[name[c1]].pb(pii(peso,name[c2]));
            adj2[name[c1]].pb(m);
        }
        ans = INF;
        for(int i = 0; i < adj[name[st]].size(); i++){
            for(int j = 0; j < n; j++)
                d[j] = INF;
            timer = adj2[name[st]][i];
            ans = min(ans,solve(name[st],name[end]));
        }
        if(ans != INF && ans != 0.0)
            printf("%f\n", ans);
        else printf("IMPOSSIBLE\n");
    }
}
