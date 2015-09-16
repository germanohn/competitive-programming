#include <bits/stdc++.h>

using namespace std;

int n, me[2005][2005], memo[2005];
char c[2005];


int pd2 (int i, int j) {
	if (i > j) 
		return 1;
	int &m = me[i][j];
	if (m != -1) return m;
	if (c[i] == c[j]) 
		return m = pd2 (i + 1, j - 1);
        return m = 0;
}

int pd (int i) {  
	if (i == n) return 0;
	int &m = memo[i];
	if (m != -1) return m;
        int mini = INT_MAX;
        for (int j = i; j < n; j++) { 
            if (pd2 (i, j) == 1)
                mini = min (mini, 1 + pd (j + 1));
        }
        return m = mini;
}

int main () {
	int cont = 1;
	while (scanf ("%d", &n) && n != 0) {
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				me[i][j] = -1;

                for (int i = 0; i < n; i++)
                    memo[i] = -1;

		scanf (" %s", c);
		printf ("Teste %d\n%d\n\n", cont++, pd (0));
	}
}
