/* Using Sparse Table
    
General idea:

- The naive approach to find the lca(u, v) would be: 
    1) guarantee that u and v are in the same depth in the tree (O(N))
    2) climb u and v one node each time in the tree until u == v (O(N))

- And if we could take a step larger than 1 and still have sure we are in a correct 
setting. This is what sparse table explores. Since the number of steps in 1) and in 2) 
have a binary representation, if we take each power of this representation as a step
we are going to reach the same point as the naive approach, but in log(H) time.

- But we have to do this from the biggest power in

-  Construct a sparse table a sparse table p[N][log H] (N: tree's size, H: tree's height), 
in which p[i][j] is the 2^j father of the node i in the tree. Then use this 

*/

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 14; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) 
            u = p[u][i];
    }

    for (int i = 14; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }

    return (u != v) ? p[u][0] : u;
}

void dfs(int u, int a, int d) {
    p[u][0] = a;
    depth[u] = d;
    for (int i = 1; i < K; i++)
        p[u][i] = p[p[u][i - 1]][i - 1];
    for (int v : adj[u]) 
        if (v != p) 
            dfs(v, u, d + 1);
}

