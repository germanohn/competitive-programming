12356: army buddies
	   WANT: dado um vetor quer saber quando tira um segmento quem sao os novos buddies
       SOLUCAO: faz um pair que guarda todos os caras vizinhos. pra cada query tira a e b
tem que fazer o vizinho da esquerda de a ter como seu vizinho a direita o vizinho da direita 
de b e o vizinho da direita de b ter como seu vizinho a esquerda o vizinho da esquerda de a,
e imprime os dois. 
       E SE: e se nao fosse de segmentos continuos
	   NÍVEL: fácil

10487: closest sums
	   WANT: Given is a set of integers and then a sequence of queries. A query gives you a number and asks to find
a sum of two distinct numbers from the set, which is closest to the query number.
	   SOLUCAO: quadraticamente faz todas as somas possiveis entre numeros da sequencia. ordena ela. entao pra cada query
anda nesse vetor de somas ordenadas e acha entre quais somas a query esta. entao ve qual a mais proxima e imprime.
	   NÍVEL: 2

146: ID codes
       next_permutation: next_permutation (iterator para comeco da sequencia, iterator para final da sequencia)
Return value: true if the function could rearrange the object as a lexicographicaly greater permutation.
Otherwise, the function returns false to indicate that the arrangement is not greater than the previous,
The first such-sorted possible permutation (the one that would compare lexicographically smaller to all other permutations)
is the one which has all its elements sorted in ascending order, and the largest has all its elements sorted in descending order.
but the lowest possible (sorted in ascending order).

