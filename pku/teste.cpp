/*programa recebe v, p que sao o numero de restaurantes e o numero
  de depositos. quer saber a soma minima que se pode conseguir*/
/*ideia é testar todas as posicoes possiveis para os depositos com pd 
//e ver qual a SOMA de distancias minimas que cada disposicao diferente 
//acarreta. o nosso subproblema otimo e supor que fiz a melhor decisao (
//deixo a cargo da dp) qual a menor soma para o intervalo i e k.*/
/*o segundo problema agora e saber quais restaurante foram escolhidos.
//ora como sei qual o custo minimo farei outra dp em que escolho um cara 
//e vejo qual a rta otima para ele. se for a rta que quero entao coloco ele
//na rta.*/
#include <bits/stdc++.h>
using namespace std;

int dp2 (int i, int k) {
    if (me[i][k] != -1) return me[i][k];
    int soma = 0;
    for (int j = i+1; j < k; j++)
        soma = min (r[j]-r[i], r[k]-r[j]);
    return me[i][k] = soma;
}

int dp (int i, int depo) {
    if (depo == 0) {
        int soma = 0;
        for (int j = i+1; j < res; j++) 
            soma += r[j]-r[i];
        return m[i][depo] = soma;
    }
    if (i == res-1)
        return 123456;
    if (m[i][depo] != -1)
        return m[i][depo];
    int ans = INT_MAX;
    for (int k = i+1; k < res; k++) {
        int soma = dp2 (i, k);
        ans = min (ans, soma+dp (i+1, depo-1));
    }
    return m[i][depo] = ans;
}

int dp3 (int ans) {
    int soma = 0;
    int ind = -1;
    while (ans > 0) {
        for (int i = ind+1; i < res; i++) {
        for (int j = 0; j < res; j++) {
            soma += r[i]-r[j];
        }
        ant = soma;
        soma += dp (i+1, d-1);
        if (soma == ans) {
            ind = i;
            ans -= ant;
        }
        }
    }
}

int main () {
    scanf ("%d%d", &res, &dep);
    for (int i = 0; i < res; i++) {
        scanf ("%d", &r[i]);
    }
    int ans = INT_MAX;
    for (int i = 0; i < res; i++) {
        int soma = 0;
        for (int j = 0; j < i; j++) 
            soma += r[i]-r[j];
        sum[i] = soma;
        soma += dp (i+1, d-1);
        if (soma < ans) ans = soma;
    }
    dp3 (ans);
    printf ("%d\n", ans);
}
