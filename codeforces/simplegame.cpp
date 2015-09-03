#include <cstdio>
#include <iostream>

using namespace std;

int main () {
	long long n, m;
	cin >> n >> m;
	long long antes, depois, a;
	antes = m - 1;
	depois = n - m;
	if (antes > depois) a = m-1;
	else {
		if (antes == depois && antes == 0) a = 1;
		else if (antes == depois) a = m-1;
		else if (antes < depois) a = m+1;
	}
	cout << a << endl;
}