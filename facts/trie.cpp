// número de vértices na trie é: quantidade de strings*(tamanho da string)
// porque o tamanho da string é a quantidade de prefixos diferentes de uma string

// calcular o número de vértices da trie no pior caso
const int MAX = ;

int k, lenS;
int trie[MAX][tamanhoAlfabeto], val[MAX];

/* monta a trie: recursivo */
void add (int idx, int idxs) {
    if (idxs == lenS) {
        val[idx] = "faz alguma coisa desejada para identificar prefixos";
        return;
    }
    if (trie[idx][s[idxs]] == 0) 
        // significa que não existe a adjacência de idx para idxs
        // logo significa que não existe o prefixo trie[idx] + s[idxs]
        // então eu crio o novo prefixo fazendo ele assumir o valor de k
        trie[idx][s[idxs]] = k++;
    add (trie[idx][s[idxs]], idxs+1);
}

/* monta a trie: iterativo */
void add (int val) {
    int v = 0;
    for (int i = pos_val; i >= 0; i--) {
        if (trie[v][((val >> i) & 1)] == 0)
            trie[v][((val >> i) & 1)] = k++;
        v = trie[v][((val >> i) & 1)];
    }
}
