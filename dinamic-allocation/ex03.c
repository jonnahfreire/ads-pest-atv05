#include <stdio.h>
#include <stdlib.h>

/*
3) Crie uma função que receba como parâmetros dois vetores
de inteiros: x1 e x2 e as suas respectivas quantidades
de elementos: n1 e n2. A função deverá retornar um ponteiro
para um terceiro vetor, x3, alocado dinamicamente, contendo
a união de x1 e x2 e usar o ponteiro qtd para retornar o tamanho de x3.
Sendo x1 = {1, 3, 5, 6, 7} e x2 = {1, 3, 4, 6, 8}, x3 irá
conter {1, 3, 4, 5, 6, 7, 8}.
Assinatura da função:
int* uniao(int *x1, int *x2, int n1, int n2, int* qtd);
*/


int* uniao(int *x1, int *x2, int n1, int n2, int* qtd){
    int i = 0, e = 0;

    for(i = 0; i < n1; i++){
        for(e = 0; e < n2; e++){
            if((x1[i] == x2[e])){
                x2[e] = 0;
            }
        }
    }
    int qt = n1;
    for(e = 0; e < n2; e++)
        if(x2[e] != 0) qt++;

    int *x3 = (int*)malloc(qt * sizeof(int));
    for(i = 0; i < n1; i++) x3[i] = x1[i];

    int c = n1;
    for(e = 0; e < n2; e++){
        if((x2[e] != 0)){
            x3[c] = x2[e];
            c++;
        }
    }
    *(qtd) = qt;
    int aux;
    for(i = 1; i < qt; i++){
        for(e = 0; e < qt -1; e++){
            if(x3[e] > x3[e + 1]){
                aux = x3[e];
                x3[e] = x3[e + 1];
                x3[e + 1] = aux;
            }
        }
    }
    return x3;
}


int main (){
    int n1 = 5, n2 = 5;
    int x1[5] = {1, 3, 5, 6, 7};
    int x2[5] = {1, 3, 4, 6, 8};
    int *qtd = 0, e = 0;

    int *x3 = uniao(x1, x2, n1, n2, &qtd);

    printf("x1 = {1, 3, 5, 6, 7}\nx2 = {1, 3, 4, 6, 8}\n");
    printf("Uniao = {");
    for(int e = 0; e < qtd; e++) printf("%d, ", x3[e]);
    printf("}\n\n\n");

    free(x3);
    return 0;
}
