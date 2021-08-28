#include <stdio.h>
#include <stdlib.h>

/*
3)Crie uma função que receba como parâmetros dois
vetores de inteiros: x1 e x2 e as suas respectivas
quantidades de elementos: n1 e n2. A função deverá
retornar um ponteiro para um terceiro vetor, x3, alocado
dinamicamente, contendo a intersecção de x1 e x2 e usar
o ponteiro qtd para retornar o tamanho de x3.
Sendo x1 = {1, 3, 5, 6, 7} e x2 = {1, 3, 4, 6, 8},
x3 irá conter {1, 3, 6}.
Assinatura da função:
int* interseccao(int *x1, int *x2, int n1, int n2, int *qtd);
*/


int *interseccao(int *x1, int *x2, int n1, int n2, int *qtd){
    int qt=0;
    for(int i = 0; i < n1+n2; i++){
        if(x1[i] != x2[i]) x2[i] = 0;
        if(x2[i] != 0) qt++;
    }

    int *x3 = (int*)malloc((qt) * sizeof(int));

    for(int i = 0; i < n2; i++){
        if((x2[i] == 0) && (x2[i+1] != 0)) x3[i] = x2[i+1];
        else x3[i] = x2[i];
    }

    *qtd = qt;
    return x3;
}


int main (){
    int n1 = 5, n2 = 5;
    int x1[5] = {1, 3, 5, 6, 7};
    int x2[5] = {1, 3, 4, 6, 8};
    int *qtd = 0;

    int *x3 = interseccao(x1, x2, n1, n2, &qtd);

    printf("\nx1 = {1, 3, 5, 6, 7}\nx2 = {1, 3, 4, 6, 8}\n");
    printf("Interseccao = {");
    for(int e = 0; e < (qtd); e++) printf("%d, ", x3[e]);
    printf("}\n\n\n");

    free(x3);
    return 0;
}
