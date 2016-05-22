3936 (justice league):
    - verifique se é possivel achar um clic tal que tirando ele o grafo fica desconexo.
       SOLUCAO: (dado o que ele quer, temos algumas propriedades: dados dois vertices ligados ou um ou outro esta
       no clic; o vertice de maior grau sempre esta no clic (define o grau do clic, esse grau sempre tem que ser menor 
       que o grau do maior grau); ordena pelo grau; forma o clic e depois ve se os caras que ficaram de fora nao se ligam

4812 (hyperactive girl): DP e aprendi mapear usando unique 
    - dado um intervalo grande (m <= 10e9), e n (n <= 100) intervalos encontre de quantas maneiras posso juntar os intervalos dados para
construir o intervalo grande de forma minimal (cada intervalo em um conjunto escolhido deve possuir ao menos um segundo 
do intervalo grande que so ele cobre)
    SOLUCAO: tem que mapear pois vou precisar trabalhar com os fins como indices. depois de fazer isso faz uma dp que tem tres estados:
i-intervalo que estou analisando, e1-fim do penultimo intervalo que coloquei, e2-fim do ultimo intervalo que coloquei. entao soma a dp (i+1, e1, e2)
com a dp (i+1, e2, novo fim) se puder.

4490 (help bubu): DP na bitmask
    - dado 1 <= k <= n <= 100, e uma sequencia com n elementos de 25 a 32 inclusivo, quero minimizar o numero de segmentos consecutivos 
iguais (mess value definido por ele). Para isso posso fazer k trocas na sequencia
    - dp com bitmask. faz quatro estados: i (elemento que estou analisando na sequencia), j (quantidade de trocas que posso fazer),
s (bitmask, em que se o i-ésimo bit estiver ligado significa que o ele ja apareceu na sequencia), l (último elemento fixado na sequencia)
      entao se percorre os elementos da sequencia da esq pra dir. pra cada elemento decide se fixa ou remove. se fixa entao compara com
o l (last) pra ver se aumenta mess value e chama dp (i+1, j, s | (1 << v[i]), v[i]. se nao, entao remove e chama dp (i+1, j-1, s, l).
pega o minimo disso
      no caso base vem a sacada. se j == 0, entao pros oito elementos diferentes que existem, se ve se eles estao presentes na sequencia
(faz um vetor de marcados na main) e dai ve se o elemento em questao ja apareceu ou nao. se ja apareceu entao posso colocar os restantes
juntos com esse ja fixo. se nao entao tenho que adicionar um na mess value devido ao bloco de elementos desse tipo que serao adicionados 
no final.

7484 (Association for the Country of Mububa): DP com busca binaria (lower_bound) e vetor de soma acumulada
    - dado 2 <= n <= 3000 briefcase (pasta), cada uma com ate 10e9 bananas, vou premiar executivos em ordem com uma quantidade de bananas.
cada executivo deve receber no minimo a quantidade de bananas que o executivo anterior recebeu. quero saber qual o maximo de executivos que
consigo premiar
    - dp com 2 estados: i (primeiro briefcase dado para o chefe que estou a premiar), j (ultima briefcase dado ao chefe que estou a premiar)
entao quando chego no estado sei que i - j (inclusivos) é suficiente para premiar o proximo chefe com o minimo de bananas do anterior. a escolha
que devo fazer é se para este chefe dou mais a proxima briefcase ou se dou esse intervalo para ele e ja defino o proximo intervalo minimo
de briefcase para o proximo chefe. 
   Na primeira escolha chamo dp (i, j+1). Na segunda escolha faco uma busca binaria (lower_bound nesse caso) em um vetor de acumulados 
para saber o primeiro briefcase k cuja quantidade de bananas de j+1 a ele seja nao menor que a quantidade de bananas do chefe anterior.
Pego o máximo disso.

4863 (balloons): guloso
    - dado n times (1000), cada time precisa de k (baloes) e esta a uma distancia da da sala A e db da sala B. sala A possui uma quantidade
A (10000) de baloes e sala b tem B (10000). quer saber qual o minimo de distancia a ser percorrida para entregar baloes para todos os times.
    - ordena os times em ordem decrescente pela maior diferenca de distancias, e entao satifaz cada um nessa ordem 

4815 (kids wishes): dfs com ciclo, e nao é DAG, porque queremos ciclo no sentido da figura.
    - dado k crianças (3 <= k <= 1e9) e w wishes (0 <= w <= 1e5) quero saber se é possível montar uma roda de crianças satisfazendo os desejos 
de todas elas. Cada criança tem no máximo 2 desejos. 
    - propriedade a ser mantida: cada criança deve sentar entre duas outras criancas.
    Então é preciso verificar se nao acontece as seguintes situacoes:
1) uma criança deseja sentar do lado de duas outras crianças, e existe outra criança diferete das anteriores que deseja sentar com a primeira.
Se for satisfazer todas nao vai preservar a propriedade acima.
2) se tiver um ciclo de criancas, esse ciclo deve contar com todas as criancas, senao nao preserva a propriedade acima.
    O problema é uma DAG, mas como se faz uma funcao para contar os vértices em um ciclo, é importante que não tenha arestas múltiplas. 
Então se usa um set.
    Para verificar primeira situação basta ver se o tamanho da lista de adjacência de alguma criança é maior que 2.
    Para verificar a segunda, basta dividir em dois casos. Se tiver apenas árvores então é possível formar o círculo. Se tiver ciclo então o ciclo
tem que ter as k crianças.
    
