#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#define MAX 4005

using namespace std;

bool A[MAX][MAX];
vector<pair <int, int> > mosq; 
vector<int> quant;

int main () {
    int nodes, edges, a, b, soma, maxi = INT_MAX;
    scanf ("%d %d", &nodes, &edges);
    for (int i = 1; i <= nodes; i++) 
        for (int j = 1; j <= nodes; j++)
            A[i][j] = false;
    for (int i = 0; i < edges; i++) { 
        scanf ("%d %d", &a, &b);
        mosq.push_back (make_pair (a, b));
        A[a][b] = true;
        A[b][a] = true;
    }
    for (int i = 1; i <= nodes; i++) {
        soma = 0;
        for (int j = 1; j <= nodes; j++) {
            if (A[i][j])
                soma++;
        } 
        quant.push_back (soma);
    }
    soma = -1;
    for (int i = 0; i < edges; i++) {
        a = mosq[i].first;
        b = mosq[i].second;
        for (int j = 1; j <= nodes; j++) {
            if (j != a && j != b && A[a][j] && A[b][j]) {
                soma = quant[a-1] + quant[b-1] + quant[j-1] - 6;
                if (soma < maxi) 
                    maxi = soma;    
            }
        }
    }
    if (soma != -1) printf ("%d\n", maxi);
    else printf ("-1\n");
}
