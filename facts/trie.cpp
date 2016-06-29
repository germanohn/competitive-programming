// calcular o número de vértices da trie no pior caso
const int MAX = ;

int k, lenS;
int trie[MAX][tamanhoAlfabeto], val[MAX];

/* monta a trie */
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


