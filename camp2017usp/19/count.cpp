#include <bits/stdc++.h>

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)
#define pb push_back
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 51;
int mat[maxn][maxn][maxn];

int memo[maxn][maxn][maxn][maxn];
int n;
int ans[maxn] = {0};
bool valid(int i, int j, int k, int sz)
{
    return( i >= 0 && j >= 0 && k >= 0 && k+sz <= n && i+sz <=n && j+sz <=n);
}
int main () {
    int t;
    cin >> t;
    while(t--)
    {
        memset(memo, 0, sizeof memo);
        memset(ans, 0, sizeof ans);
        memset(mat, 0, sizeof mat);
        cin >> n;
        vector<int> vec(n*n*n);
        rp(i, n*n*n){
            cin >> vec[i];
        }
        rp(i, n){
            rp(j, n){
                rp(k, n){
                    mat[i][j][k] = vec[i*n*n + j*n + k];
                    memo[i][j][k][1] = mat[i][j][k];
                    if(mat[i][j][k] == 1) ans[1]++;
                }
            }
        }
        fr(sz, 2, n+1){
            rp(i, n){
                rp(j, n){
                    rp(k, n){
                        if(!valid(i,j,k,sz)){
                            continue;
                        }
                        int curMx = -1;
                        curMx = max(curMx, memo[i][j+1][k][sz-1]);
                        curMx = max(curMx, memo[i][j][k+1][sz-1]);
                        curMx = max(curMx, memo[i][j+1][k+1][sz-1]); 
                        curMx = max(curMx, memo[i][j][k][sz-1]);
                        
                        curMx = max(curMx, memo[i+1][j+1][k][sz-1]);
                        curMx = max(curMx, memo[i+1][j+1][k+1][sz-1]);
                        curMx = max(curMx, memo[i+1][j][k][sz-1]);
                        curMx = max(curMx, memo[i+1][j][k+1][sz-1]); 
                        memo[i][j][k][sz] = curMx;
                        if(sz == curMx) ans[sz]++;
                    }
                }
            }
        }
        fr(i, 1, n+1){
            cout << ans[i] << " " ;
        }
        cout << endl;
    }
    return 0;
}

