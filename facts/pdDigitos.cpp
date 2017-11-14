// é uma pd para construir numeros
// entao o caso base sera quando terminei de construir.
// logo sempre construo o numero do digito mais significativo para o menos significativo
// pois varios sufixos irao se repetir logo por essa pd top-down nao precisarei construir
// mais de uma vez
// Estados:
// - i: digito do numero que estou montando
// - o segundo parametro pode variar entre sum (soma de digitos de interesse), ult (ultimo 
// digito que apareceu) e outros
// - pre: booleano que é true se o numero que construi ate agora é igual, e falso se
// o numero que contrui é diferente
// o quarto parametro "f" geralmente é usado para ver se pode colocar ou nao um 0. 
// se ele for true significa que coloquei um numero diferente de 0 na construcao do numero 
// entao posso colocar 0 que ele nao sera leading zero. caso contrario (f == false) se colocar
// 0, este sera leading zero

// geralmente se faz transforma os numeros em questao em string usando sprintf (str, "%d", num);

int dp (int i, int sum, bool pre) {
    if (i == -1) 
        return 0;
    if (me[i][sum][pre] != -1)
        return me[i][sum][pre];
    int ans = 0;
    for (int dig = 0; dig <= 9; dig++) {
        if (pre && dig > str[i]-'0') break;
        // se passou pelo if significa que ou
        // o prefixo que contrui nao é igual ao numero e, portanto, posso colocar qualquer dig pois por
        // construcao sempre construo um numero menor ou igual ou 
        // o prefixo que contrui é igual ao numero e entao o dig que estou colando é menor que str[i]
        // assim por essa condicao de break sempre garanto que estou construindo um numero menor ou igual
        // a str.
        ans += dp (i+1, s + (dig == str[i]-'0'), pre & (dig == str[i]-'0'));
    }
    return ans;
}

// problemas de interesse:
// - digit count (live archive) 
// - how many ones needed (live archive)
// - space elevator (uva)
// - hill number (live archive)
