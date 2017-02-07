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

116-a.cpp: usar max

300-a.cpp: algoritmo construtivo

259-a.cpp: ideia em tabuleiro de xadrez legal

208-a.cpp: manipulacao de string

137-b.cpp: vetor de frequencia, aparece ideia de permutacao

242-a.cpp: brute force legal

188-b.cpp: constructive algorithm interessante!

152-a.cpp: implementação

339-b.cpp: implementação

122-a.cpp: brute force facil

160-a.cpp: guloso e sorting

41-a.cpp: implementação facil com strings

58-a.cpp: guloso, string, legal

96-a.cpp: implementacao facil com strings

224-a.cpp: achar lados de um paralelepipedo baseado em suas tres areas

219-a.cpp: vetor de freq, k-string (facil mas interessante)

230-a.cpp: guloso, sorting (da pra usar vetor de permutacao)

337-a.cpp: guloso (legal), brute

257-b.cpp: guloso, jogos, escolha otima (legal)
 
239-a.cpp: guloso, implementacao facil

242-b.cpp: implementacao facil

*459-b.cpp: - problema: achar a maior diferenca em um vetor e quantos pares de numeros nele geram essa diferenca
            - implementacao legal e interessante pra treinar rapidez, clareza de ideias, corners e um pouquinho de combinatoria

285-c.cpp: - problema: achar o menor custo pra transformar uma seq de n numeros inteiros em uma permutacao
           - sort, guloso (o primeiro do menor é o que tem menor custo para ser o primeiro da permutacao e assim pordiante). Legal

253-a.cpp: - guloso facil e aprende a manipular arquivo com fopen, fscanf, fprintf
           - coloca o que tem mais na primeira posicao, depois vai intercalando entre os dois ate um acabar, e depois completa com o outro ate o final

349-a.cpp: - guloso facil

166-a.cpp: - implementacao facil

276-b.cpp: - jogos, guloso, palindromos, facil

222-b.cpp: - classico, implementacao, vetor com equivalencias, bem importante e legal a ideia pra quem esta comecando!

109-a.cpp div1: problema bem legal de brute force e implementacao, bom pra treinar implementacao da ideia!

743-a.cpp div2: guloso, sacada bem legal!

217-a.cpp div1: formar componentes e conta-las (os que estao na mesma componente se atingem). Entao pode pensar como um grafo bipartido e contar as
componentes, ou fazer com union find. Legal!

368-b.cpp div2: ver quantos numeros diferentes tem a partir de um i de um vetor nao ordenado. Basta percorrer de tras pra frente, preprocessando. Legal

602-b.cpp div2: - achar a maior sequencia de numeros tais que o maior e o menor numero da sequencia tem diferenca de no max 1
                - problema MUITO INTERESSANTE, que por ter a propriedade de |Ai - Ai-1| <= 1, entao da pra fazer em O(n), comparando sempre as duas ultimas 
                  diferencas nao negativas. Poderia ficar mais interessante e dificil se permitisse a diferenca de elementos consecutivos ser maior que 1, 
                  e a diferenca entre elementos da sequencia ser maior que 1. (ai teria que fazer com o multiset)

327-b.cpp div2: - construir uma sequencia de 10^5 numeros de no max 10^7, em que os numeros estejam em ordem crescente e o numero de indice i nao pode 
                ser divisivel por nenhum menor que ele na sequencia. Problema com uma sacadinha.

313-b.cpp div2: - problema classico de soma acumulada. 
                - Fácil, mas útil pra pegar a ideia

363-b.cpp div2: - problema classico de soma acumulada tambem
                - Fácil, mas tem uma solucao alternativa interessante: como quer a menor soma de um segmento de k numeros consecutivos, pode somar os 
                primeiros k, entao tira o primeiro e soma o k + 1, tira o segundo e soma o k + 2 e assim por diante ate o final da sequencia, pega o 
                minimo disso.

230-b.cpp div2 (t-prime): - dizer se um numero de 10^12 tem 3 divisores positivos
                          - os t-primes sao quadrados perfeitos de numeros primos, entao basta fazer uma lista com os quadrados de todos os primos ate
                          10^6, e ver se o numero esta nessa lista. BEM INTERESSANTE (TEORIA DOS NUMEROS)

327-a.cpp div2: - classico problema de achar max subsequence sum
                - mas da pra fazer O(n^3)

189-a.cpp div2: - dado tres partes e um numero n, representar n como a maior quantidade possivel dessas tres partes
                - brute force ou dp facil. No brute ideia interessante de fixar 2 e depois testar com o terceiro

372-a.cpp div1: - guloso INTERESSANTE, tive DIFiculdade em achar a sacada de dividir em dois conjuntos pra entao aplicar a estrategia gulosa

166-c.cpp div2: - guloso simples, mas tive um pouco de DIFiculdade pra implementar (calcular quantidade de elementos antes e depois de uma posicao).
                - licao: quando tiver que calcular posicoes e quantidades, defina novas variaveis que facilitem a vizualicao do que esta sendo feito 
                e considerado.

322-b.cpp div2: - matematica INTERESSANTE, tive um pouco de DIFculdade pra resolver e nao cheguei exatamente na solucao esperada. O que tinha que perceber
                era que se faria no maximo 2 buques mistos, porque 3 buques mistos equivale a fazer 3 individuas. Assim bastava testar fazer 0, 1, ou 2 buques
                mistos e mais o que sobrou. Fazendo essa reducao ficava muito facil. O que eu fiz foi perceber que podia reduzir as quantidades pra valores <= 3
                e dai tratava os casos.

492-c.cpp div2: - sorting e guloso simples, mas bom para treinar, nao tive dificuldade
                - tem que formar uma media, e para isso tem que aumentar a media com os que custam menos

363-c.cpp div2: - guloso INTERESSANTE, depois que saquei foi tranquilo.
                - uma parte foi pensar o que acontecia quando tinha dois, e depois tres pares consecutivos, qual era a decisao otima. Depois foi adicionar
                o caso com tres ou mais nisso.

235-a.cpp div1: - teoria dos numeros: dado um n(10^6) achar o maior lcm de 3 numeros nao necessariamente diferentes menores ou iguais a n.

118-d.cpp div2: - dp: dp bem simples de contagem, os limites sao pequenos

276-c.cpp div2: - Problema simples, mas BEM LEGAL pra treinar implementacao, sorting e ideia de soma acumulada em intervalos 

486-c.cpp div2: - Problema INTERESSANTE, guloso (encontrar estrategia otima, e que basta anda na metade da string)
                  com pratica de implementacao (pensar em indices em uma string e na distancia de letras no alfabeto

224-b.cpp div2: - Problema INTERESSANTE, two pointers e vetor marcando a ultima ocorrencia de um elemento no vetor

?? rever 485-a.cpp div2: - Problema bem INTERESSANTE, regras de congruencia e tambem com vetor de seen

320-b.cpp div2: - Problema simples de dfs. Pensa em cada no como um no de um grafo, faz uma aresta direcionada
                  conforme ele especifica quando tem uma aresta indo de u pra v, e depois basta ver se um vertice
                  alcança outro usando uma dfs.

377-a.cpp div1: - Problema MUITO LEGAL, com ideia simples e interessante, bastando fazer uma bfs ou dfs. Tambem legal que a estrategia gulosa de ir pegando
                  quem tem menos vizinhos nao funciona (cheguei a pensar nisso)

441-c.cpp div2: - Problema bem simples de construtive algorithm, basta navegar em uma matriz de uma determinada forma. Depois faz k - 1 tubos de tamanho 2,
                  depois o ultimo tubo com o restante de celulas.

337-b.cpp div2: - Muito LEGAL e IMPORTANTE, me ajudou bastante a entender mais de proporcoes.

289-b.cpp div2: - Problema muito LEGAL e INTERESSANTE de SORTING, BRUTE FORCE e IMPLEMENTAÇAO. Primeiro importante notar que se dois numeros deixam 
                  restos diferentes em relacao a um numero d, 
                  entao nao importa quantas vezes se some ou subtraia d deles eles continuaram nao deixando o mesmo resto. Entao essa é uma relacao 
                  importante de se saber, deixar dois numeros IGUAIS, IMPLICA que eles terao o mesmo resto quando divididos por qualquer numero.
                  
455-a.cpp div1: - DP bem simples de knapsack, mas bom pra treinar DP ITERATIVA.

192-a.cpp div2: - Problema interessante de BRUTE FORCE (estrategia recorrente de tendo dois valores pra analisar, 
                  fixa-se um deles e o outro e encontrado rapidamente e verificado. 
                  Entao a sacada era perceber que tanto "a" quanto "b" poderiam
                  valer no max 10^5, assim se podia se fixar um pra testar todos os valores de 1 ate 10^5, e o 
                  outro nao fixado deveria ser a raiz quadrada do "n" menos a parcela devida ao numero fixado. 

467-c.cpp div2: - DP bem simples de maximizar a soma de k intervalos escolhidos em um array, ou seja, um knapsack
                  de intervalos, bastando usar um vetor de soma acc para a soma dos intervalos. 

*** 339-c.cpp div2: - DP/dfs. Problema simples, mas ESSENCIAL, bom porque tem uma sacadinha da balança em um 
                  dos estados
                  e também porque tem a reconstrução de resposta que fiz na mesma função usando uma stack. Além 
                  disso, é uma dp que por tras é um grafo em que os estados são vértices e os arcos entre vértices
                  são os movimentos permitidos no problema. Então o que estamos querendo e fazendo na dp, na 
                  é encontrar um caminho nesse grafo do estado inicial com "m" movimentos até o estado final 
                  com "0" movimentos e a balança respeitando a relação imposta no problema. LEGAL!

339-d.cpp div2: - SEGMENT TREE. Simples, mas com o detalhe da distancia pra folha que muda a operacao que tem que ser feita. Cada update vai ser 
                  O(log(2^n)) = O(n), e como n <= 17, para m <= 10^5 query esta ok! LEGAL! 

253-b.cpp div2: - TWO POINTERS bem interessante, ou BRUTE FORCE (fixando um valor para smallest) e BINARY SEARCH (para o chutar o maior que ainda da) e 
                  e soma acc para saber quantos vao ser tirados. Problema que tive dificuldade e vale a pena fazer e entender!

*** 350-c.cpp div2: - SORTING E GREEDY. A sacada do problema era descobrir em qual ordem visitar os pontos, de forma que eu visitar um nao passasse por 
                  de outro. É um conceito bem importante, porque esse problema mostra como a partir de um ponto visitar outros sem passar por cima 
                  de algum ponto no meio do caminho. Uma forma era sortar por distancia Manhattan. Isso valeria pois se um ponto "a" estiver no 
                  caminho de um ponto "b", entao "a" tem dis manhattan inferior a "b". MUITO LEGAL e IMPORTANTE CONCEITO esse problema.

*** 466-c.cpp div2: - BRUTE FORCE com SOMA ACUMULADA, muito interessante esse problema e da pra fazer em O(n).

*251-a.cpp div1: - Binary search, combinatorics, two pointers. Além da ideia de two pointers, tem a ideia legal de fixar um cara para evitar contar 
                  coisas mais de uma vez. Problema fácil, mas interessante.

453-a.cpp div1: - Probabilidades, valor esperado. Problema interessante de contagem, usando a ideia de valor esperado e ainda com um truque na conta 
                  para evitar overflow. Problema fácil, mas se fosse a soma de todas as jogadas, acho que seria bem mais difícil. 

414-b.cpp div1: - Combinatorics, dp construtiva. Achar um conjunto de numeros que preserva uma propriedade. Faz uma dp que seleciona os elementos do 
                  conjunto (dp construtiva) de modo a respeitar a propriedade e no final soma todos os conjuntos construidos.

** 353-a.cpp div2: - Math. Problema muito legal para treinar tratamento de casos.

*** 349-b.cpp div2: - Guloso muito legal! Construir o maior numero possivel, sendo que os digitos tem um custo. 

764-a.cpp div2: - Continha bem fácil

764-b.cpp div2: - Constructive algorithm. Dava uma sequencia final, e tinha que encontrar a sequencia que tinha originado ela, dados as operações 
                  permitidas. Tinha um padrão na sequencia, depois que via ficava facil.

* 764-c.cpp div2: - Dfs bem legal e de pintar grafo!

