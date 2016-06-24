Importante:
    - Vetor de bit é indexado de 1 a n (número de bits do maior valor (geralmente tamanho do vetor em questao)
    - update é até o n
    - query ate maior que 0
    - To generalize this every index i in the BIT[] array stores the cumulative sum from the index i to i - (1<<r) + 1 (both inclusive), where r represents the last set bit in the index i
    - Let’s see how to construct this tree and then we will come back to querying the tree for prefix sums.

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

