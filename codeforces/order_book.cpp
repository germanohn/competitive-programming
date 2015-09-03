#include <cstdio>
#include <map>
#include <algorithm>
#define MAX 1010

using namespace std;

int n, s;
int price, quant;
char dir;
map<int, int > sell;
map<int, int > buy;

struct store {
	int quant, price;
};

store livro[MAX];

bool compara (store x, store y) {
	return x.price > y.price;
}

int main () {
	scanf ("%d%d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf ("%c%c %d %d", &dir, &dir, &price, &quant);
		if (dir == 'S') {
			if (sell.find (price) == sell.end ()) {
				sell.insert (make_pair (price, quant));
			}
			else 
				sell[price] += quant;
		}

		else if (dir == 'B') {
			if (buy.find (price) == buy.end ()) {
				buy.insert (make_pair (price, quant));
			}
			else 
				buy[price] += quant;
		}
	}
	map<int, int> ::iterator it;

	int j = 0;
	for (it = sell.begin (); it != sell.end (); it++) {
		livro[j].price = (*it).first;
		livro[j].quant = (*it).second;
		j++; 
	}
	if (s < sell.size ()) sort (livro, livro + s , compara);
	else sort (livro, livro + sell.size () , compara);
	for (int i = 0; i < s && i < sell.size (); i++) 
		printf ("S %d %d\n", livro[i].price, livro[i].quant); 

	j = 0;
	for (it = buy.begin (); it != buy.end (); it++) {
		livro[j].price = (*it).first;
		livro[j].quant = (*it).second;
		j++; 
	}
	sort (livro, livro + buy.size() , compara);
	for (int i = 0; i < s && i < buy.size (); i++) 
		printf ("B %d %d\n", livro[i].price, livro[i].quant); 
}