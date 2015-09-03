#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int,string> pis;

int main(void){

	int n, t;

	cin >> n >> t;

	vector<pis> vp;

	for(int i = 0; i < n; i++){
		int lvl;
		string nome;
		cin >> nome >> lvl;
		vp.push_back(pis(-lvl, nome));
	}

	sort(vp.begin(), vp.end());

	for(int i = 1; i <= t; i++){
		cout << "Time " << i << endl;
		vector<string> time;
		
		for(int k = i-1; k < n; k+=t){
			time.push_back(vp[k].second);
		}

		sort(time.begin(), time.end());

		for(int k = 0; k < time.size(); k++){
			cout << time[k] << endl;
		}

		cout << endl;
	}
	return 0;
}