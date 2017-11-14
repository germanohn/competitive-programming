#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = (int)A.size();
    printf("n %d\n", n);
    vector<int> v;
    vector<vector<int> > ans;
    stack<tuple<int, int, int, int> > perm;
    v.push_back(0);
    perm.push(make_tuple(0, 0, 0, 0));
    printf("antes while\n");
    
    while (!perm.empty()) {
        printf("perm size %d\n", perm.size());
        tuple<int, int, int, int> x = perm.top();
        printf("depois perm size\n");
        perm.pop();
        int i = get<0>(x);
        printf("size %d i %d j %d seen %d mask %d\n", perm.size(), get<0>(x),
                                                      get<1>(x), get<2>(x), get<3>(x));
        
        if (i == n) {
            printf("i == n\n");
            if (!v.empty()) { 
                printf("antes v\n");
                v.pop_back();
                ans.push_back(v);
                printf("depois v\n");
            }
        } else {
            printf("antes if v.empty()\n");
            printf("antes seen\n");
            v.pop_back();
            int seen = get<2>(x);
            int mask = get<3>(x);
            printf("depois seen\n");
            for (int j = get<1>(x); j < n; j++) {
                printf("A[j] %d\n", A[j]);
                int cur = A[j];
                if (((1 << cur) & seen) == 0 && ((1 << j) & mask) == 0) {
                    printf("cur %d seen %d mask %d\n", cur, seen, mask);
                    perm.push(make_tuple(i, j + 1, seen | (1 << cur), mask | (1 << j)));
                    perm.push(make_tuple(i + 1, 0, 0, mask | (1 << j)));
                    v.push_back(cur);
                    v.push_back(0);
                    break;
                }
            }
        }
    }

    printf("depois while\n");
    
    return ans;
}

int main() {
    int n;
    scanf(" %d", &n);

    vector<int> A(n);
    vector<vector<int> > ans;

    printf("n %d\n", n);

    for (int i = 0; i < n; i++) {
        scanf(" %d", &A[i]);
    }


    printf("antes permute\n");
    ans = permute(A);
    printf("depois\n");
    for (auto v : ans) {
        printf("-> ");
        for (auto x : v) {
            printf("%d ", x);
        }
        printf("\n");
    }
}
