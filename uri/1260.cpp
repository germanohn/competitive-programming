#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

map<string, int> tree;

int main () {
	int n, cont;
	char s;
	string a;
	scanf ("%d", &n);
	scanf ("%c%c", &s, &s);	
	while (n--){
		cont = 0;
		getline (cin, a);
		while (a.size() != 0){
			if (tree.find (a) != tree.end())
				tree[a]++;
			else 
				tree[a] = 1;
			cont++;
			getline (cin, a);
		}
		map<string, int>::iterator it;
		for (it = tree.begin(); it != tree.end(); it++){
			double b = (double)((*it).second)/cont; 
			cout << (*it).first << " ";
			printf("%.4f\n", b*100);
		}
		if (n >= 1) printf ("\n");
		a.clear();
		tree.clear();
	}	
}	