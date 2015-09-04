#include <stdio.h>

int main() {

  int j,n,balance,in,actual,cont=0;

  scanf("%d", &in);   
  while (in != 0) {
    for (j = 0; j< in;j++) {
      scanf("%d", &actual);
      if (actual > 0)  
        balance++;
      else
        balance--;
    }
    cont++;
    printf("Case %d: %d\n", cont, balance);
    balance = 0;
    scanf("%d", &in);
  }
return 0;
}
