#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#define MAX 85

using namespace std;

int main () {
	int t, n, m;
	char nada;
	string pa, tr, pala;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d%c", &m, &n, &nada);
		map<string, string> mp;
		for (int i = 0; i < m; i++) {
			getline (cin, pa);
			getline (cin, tr);
			mp.insert (make_pair (pa, tr));
		}
		map<string, string>::iterator it;
		while (n--) {
			getline (cin, pa);
			int k = 0;
			bool pula = 0;
			while (k < pa.size ()){
				pala.clear ();
				while (pa[k] != ' ' && k < pa.size ())
					pala += pa[k++];
				k++;
				if (pula)
					printf (" ");
				it = mp.find (pala);
				if (it != mp.end ())
					cout << it->second;
				else 
					printf ("%s", pala.c_str ());
				pula = 1;
			}
			printf ("\n");
		}
		mp.clear ();
	}
}