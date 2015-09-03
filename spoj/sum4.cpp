#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 4004
#define pb push_back

using namespace std;

int main (){
	int n, m[MAX][4];
	vector <int> soma;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			scanf("%d", &m[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			soma.pb (m[i][0] + m[j][1]);
	sort (soma.begin(), soma.end());
	int ans = 0, num;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			num = - (m[i][2] + m[j][3]);
			pair < vector<int> ::iterator, vector<int> ::iterator> bound;
			bound = equal_range (soma.begin(), soma.end(), num);
			ans += bound.second - bound.first;
		}
	}
	printf ("%d\n", ans);
}