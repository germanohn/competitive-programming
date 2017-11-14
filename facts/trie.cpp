Problemas relacionados: 

- 817-e.cpp  
- tap2016: g.cpp (efficient managing (spoj))

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

// trie T é um digrafo aciclico, em que para cada vertice, existe um caminho dele ate
// a raiz. A cada aresta esta associado um caractere, e de um mesmo no nao saem
// duas arestas associadas ao mesmo caractere.
//
// Então todo nó já comeca tendo um numero maximo de elementos na sua lista de adj:
// ∑ (alfabeto). Cada nó representa um prefixo na trie, entao dado um conjunto S
// de strings é preciso saber quantos prefixos são possiveis pra declarar a matriz.
//
// Assim um caminho da raiz r ate um vertice u, representa uma string s, e para 
// cada string s existe um unico caminho que representa ela. Assim, 
// quando se deseja inserir s em uma trie, se faz o caminho sugerido pelos caracteres
// de sua string. Ao terminar se marca que o prefixo formado de r ate esse vertice
// u é a string desejada.
//
// utilidades: Dada uma trie T, um conjunto de strings S = {S1, ..., S2}, é possivel 
// saber se uma string P esta na trie T em O(|P|). Para isso basta seguir em T o 
// caminho P[1], P[2], ... , P[|P|], se possivel. Se for possivel chegar ao final 
// e o o no final for um do nos marcados de T, entao P pertence S. Para implementar
// basta fazer um funcao que retorna o maior prefixo comum em trie.
