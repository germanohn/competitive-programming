#include<bits/stdc++.h>
using namespace std;

int n;
int v[105];
priority_queue<int> pq;

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);

    for (int i = 1; i < n; i++) 
        pq.push(v[i]);

    int acc = v[0], bribe = 0;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        if (x >= acc) 
            x--, pq.push(x), bribe++, acc++;
        else 
            break;
    }

    printf("%d\n", bribe);
}
