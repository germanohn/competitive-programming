#include <stdio.h>

int main() {
        int N, num1, num2, soma;
        scanf("%d", &N);
        for (; N > 0; N--) {
                scanf("%d %d", &num1, &num2);
                if (num1 > 10) num1 = reverse(num1/10, num1%10);
                if (num2 > 10) num2 = reverse(num2/10, num2%10);
                soma = num1 + num2;
                if (soma > 10) soma = reverse(soma/10, soma%10);
                printf("%d\n", soma);
        }
        return 0;
}

int reverse(int number, int numberReverse) {
        if (number < 10) return number + 10*numberReverse;
        else return reverse(number/10, 10*numberReverse + number%10); 
}
