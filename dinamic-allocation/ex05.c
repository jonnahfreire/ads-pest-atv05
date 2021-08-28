#include <stdio.h>
#include <stdlib.h>

/*
5) Analise o código abaixo e determine o valor das variáveis ao final da execução.
int i=34,j;
int *p;
p = &i;
*P++;
j = *p + 33;
*/


int main (){
    int i = 34, j;
    int *p;
    p = &i;
    *p++;
    j = *p + 33;

    printf("\ni = %d\np = %d\nj = %d\n", i, *p, j);

    return 0;
}
