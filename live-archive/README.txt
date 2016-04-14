3936.cpp (justice league):
    - verifique se é possivel achar um clic tal que tirando ele o grafo fica desconexo.
       SOLUCAO: (dado o que ele quer, temos algumas propriedades: dados dois vertices ligados ou um ou outro esta
       no clic; o vertice de maior grau sempre esta no clic (define o grau do clic, esse grau sempre tem que ser menor 
       que o grau do maior grau); ordena pelo grau; forma o clic e depois ve se os caras que ficaram de fora nao se ligam

4812.cpp (hyperactive girl):
    - dado um intervalo grande (m <= 10e9), e n (n <= 100) intervalos encontre de quantas maneiras posso juntar os intervalos dados para
construir o intervalo grande de forma minimal (cada intervalo em um conjunto escolhido deve possuir ao menos um segundo 
do intervalo grande que so ele cobre)
    SOLUCAO: tem que mapear pois vou precisar trabalhar com os fins como indices. depois de fazer isso faz uma dp que tem tres estados:
i-intervalo que estou analisando, e1-fim do penultimo intervalo que coloquei, e2-fim do ultimo intervalo que coloquei. entao soma a dp (i+1, e1, e2)
com a dp (i+1, e2, novo fim) se puder.
