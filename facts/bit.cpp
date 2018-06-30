Importante:
    - Vetor de bit é indexado de 1 a n (número de bits do maior valor (geralmente tamanho do vetor em questao)
    - update é até o n
    - query ate maior que 0
    - To generalize this every index i in the BIT[] array stores the cumulative sum from the index i to i - (1<<r) + 1 (both inclusive), where r represents the last set bit in the index i
    - Let’s see how to construct this tree and then we will come back to querying the tree for prefix sums.

Problemas:

COUNT INVERSIONS:
    Ideia: Inversão é quando um par de números aparece em ordem contrária em relação a duas permutações. Supondo
    que uma das permutações está em ordem crescente, então teremos uma inversão quando para um par de números m
    e M que aparece assim na permutação ordenada (m, ..., M), aparece assim (M, ..., m) na segunda. Tendo a segunda 
    como referência, a resposta é conseguida de duas maneiras:
    1) contar a quantidade de m que aparecem depois de M: i - query(M) (se iterar da esquerda para a direita na bit)
    2) contar a quantidade de M que aparecem antes de m: query(MAX - 1) - query(M) (se iterar da esquerda para a direita na bit
    No primeiro problema faço 1), no segundo faço 2)

    - nwerc2015 g.cpp, ideia: contar inversões entre duas permutações, mas tem uma sacadinha pra ver que resposta
está só em função disso.
    - invcnt spoj: aplicação direta

void update (int idx, int val) {
    for (int i = idx; i <= n; i += i&-i)
        bit[i] += val;
}

int query (int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

