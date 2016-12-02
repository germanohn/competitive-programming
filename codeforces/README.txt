-educational 11 (660), sacadas:
    A: imprimir array cujos elementos adjacentes sejam coprimos 
       (pegar gdc entre dois numeros, se for diferente de 1, adiciona 1 entre os dois numeros no vetor)
    B: dado onibus com filas de 4 bancos, imprimir ordem de saida dos passageiros do onibus
       (montagem e simulacao inteligente com matrizes)
    C: vetor de 0, 1, quer a maior sequencia com k zeros
       (two pointers)
    D:

-educational 12 () foi bem daora (ver o d bem legal):

-contest 335 (606)
    A: dadas tres cores tenho uma quantidade de cada e uma quantidade que preciso. sabendo que posso transformar duas cores
iguais em uma cor qualquer, quero saber se é possivel conseguir o que preciso.
       SOLUCAO: guarda duas variaveis: has e need. no final veremos qual é maior. entao anda linear nas 3, pra cada cor ve se ela
contribui para has ou need.
    C: dada uma sequencia de n inteiros, quero ordenar ela no minimo numero de operaçoes. É permitido pegar qualquer elemento e 
coloca-lo no comeco ou no final da sequencia.
       SOLUCAO: ideia é que quero minimizar o número de elementos que precisarão se mover no vetor. Isso é equivalente a maximizar o número de elementos que ficarão
parados. Então a sacada é ver quando uma cadeia de elementos não é alterada. É quando os elementos delas estão em ordem crescente 
na sequência e sem pulos. Ex: 3 6 4 5 1 2, nela 3 4 5 formam uma cadeia dessas. Então o problema vira achar a lis (longest increasing
substring) em um vetor que guarda pra cada elemento a posição que ele aparece na sequencia. Veja que substring e nao subsequence.
Let’s suppose we removed from the array all that elements we would move. What remains? The sequence of the numbers in a row: a, a+1, …, b. The length of this 
sequence must be maximal to minimize the number of elements to move. Consider the array pos, where pos[p[i]] = i. Look at it’s subsegment pos[a], pos[a+1], …, pos[b]
. This sequence must be increasing and its length as mentioned above must be maximal.
So we must find the longest subsegment of pos, where pos[a], pos[a+1], …, pos[b] is increasing.
       Importante: se pudesse elementos repetidos entao nao pode ser guloso, seria uma dp.

-contest 351 (673)
    A: ad-hoc. tem um jogo com 90 minutos, sendo que alguns deles sao interessantes, se passar 15 minutos sem minutos interessantes, ele
desliga a tv. Ele dara n minutos interessantes, quer saber quantos minutos o cara vai assistir de jogo.
       SOLUCAO: faz um for que recebe o minuto atual mais interessante (cur) e compara com o anterior mais interessante (prev) 
    B: ad-hoc. dado n problemas quero separar em div1 e div2 seguindo algumas regras. quero saber quantas possibilidades existe. Regras: 
problemas similares nao podem estar na mesma divisao; nao pode existir nenhum problema na div2 melhor que na div1; as divisoes nao podem 
estar vazias; cada problema so pode estar em uma divisao. 
       SOLUCAO: a ideia é primeiro e ver os caras que necessariamente tem que estar em cada divisao. Isso se ve, analisando os similares. suponha que a < b
sao similares, entao a tem que estar em div2 e b em div1. Feito isso, os restantes podem estar tanto em div1 como em div2. Esse numero sera a diferenca
entre o menor da div1 mi1 e o maior da div2 mx2. Cuidado para inicializar mi1 = n e mx2 = 1. E quando a diferenca der menor igual a zero tem que ser 0 a rta
Eu tinha feito com um vetor de mark e um set. Como a resposta sera mi1 - mx2 entao se tiver um elemento que esta tanto 
na div1 quanto na div2 entao quando fizer a conta a rta sera 0, logo nao preciso do set. Como cada elemento que nao tinha similares (sobrou) contribui com uma
possibilidade entao nao precisa marcar os que ja foram usados pra saber os que nao foram, basta fazer a diferenca mesmo.
    C: ad-hoc. dado n baloes (1 <= n <= 5000) e um sequencia de n numeros com as cores de cada balao (cores tambem de 1 a 5000), imprima pra cada cor (1 a n) 
o número de intervalos em que ela é dominante. cor dominante é quando em um intervalo o numero dela aparece mais vezes. 
       SOLUCAO: Existem n*(n+1)/2 intervalos, pra cada i existem n-i intervalos partindo dele com ele como comeco. entao o que se faz é analisar pra cada i todos 
os intervalos que comecam em i crescentemente. Dessa forma ao aumentar o intervalo so ira incrementar as frequencias e dai comparo com o maior do intervalo anterior
    D: ad-hoc. dado n vertices, k arestas, a, b, c, d. 


-591-b.cpp Rebranding:
     WANT: dado n (tamanho da strings), m (numero de trocas), cada troca envolve duas letras a e b, e envolve
     trocar todos os a's da newest string por b's e contrario tambem. quer a string final apos m trocas
     SOLUCAO: as posicoes da string estao divididas em grupos. No comeco cada letra é dona de um grupo. basta
     saber no final qual letra vai ser a dona de um determinado grupo de posicoes.
     NÍVEL: Médio
     IMPLEMENTAÇÃO: Fácil
     QUALIDADE: MUITO LEGAL, INTERESSANTE

-569-c.cpp (Primes or Palindromes): maior quantidade de primos ate um numero n é n/log n, de palindromes é 
    Want: quer saber qual o maior valor de n tal que a quantidade de primos ate ele é menor igual a quantidade de palindromes ate ele vezes um dado A, em que
A = p/q, com 1 <= p, q <= 42.
    Solucao: basta calcular os primos ate 10000007, e entao faz uma soma acumulada de primos e de palindromos e entao faz uma pesquisa linear de 1 ate MAX pra
ver qual o maior n que satisfaz a propriedade. Importante: por causa o do A, a funcao nao é crescente logo nao se pode usar busca binaria.

contest 711:
    a: so fazer
    b: so fazer
    c: dp facil
    d: de contagem em grafos, mas estranho, nao entendi direito
    

432-a.cpp: greedy, implementation (nivel 1)

110-a.cpp: implementation (nivel 1)

141-a.cpp: vetor de freq

200-b.cpp: porcentagem
 
224-b.cpp: two pointers (importante)

148-a.cpp: Insomnia cure
    como ver que um numero tem todos os digitos diferentes (linear com vetor de tamanho maior numero e flag de turn)
