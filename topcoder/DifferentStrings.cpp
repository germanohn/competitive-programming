#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

class DifferentStrings {
	public:
	int minimize(string A, string B) {
        int tamA = A.length (), tamB = B.length ();
        int ma = INT_MIN, ans;
        for (int i = 0; i < tamB-tamA+1; i++) {
            int cont = 0, k = 0;
            for (int j = i; j < i+tamA; j++) {
                if (A[k] == B[j]) 
                    cont++;
                k++;
            }
            ma = max (ma, cont);
        }
        ans = tamA-ma;
        return ans;
	}
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string A                  = "koder";
			string B                  = "topcoder";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string A                  = "hello";
			string B                  = "xello";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string A                  = "abc";
			string B                  = "topabcoder";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string A                  = "adaabc";
			string B                  = "aababbc";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string A                  = "giorgi";
			string B                  = "igroig";
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = DifferentStrings().minimize(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
