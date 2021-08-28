#include <stdio.h>
#include <stdlib.h>

/*
2) Faça uma função que receba um valor n e crie dinamicamente
 um vetor de n elementos e retorne um ponteiro. Crie uma função
 que receba um ponteiro para um vetor e um valor n e imprima os n
 elementos desse vetor. Construa também uma função que receba um
 ponteiro para um vetor e libere esta área de memória. Ao final,
 crie uma função principal que leia um valor n e chame a função
 criada acima. Depois, a função principal deve ler os n elementos
 desse vetor. Então, a função principal deve chamar a função de
 impressão dos n elementos do vetor criado e, finalmente, liberar
a memória alocada através da função criada para liberação.
*/

int *dinamicVector(int n){
    int *vetor = (int*)malloc(sizeof(int) * n);
    return vetor;
}


void memoryFree(int *x) {
    free(x);
}


void printValues(int *vetor, int n) {
    for(int i = 0; i < n; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}


int main (){
    int n;
    printf("Digite um inteiro qualquer: ");
    scanf("%d", &n);

    int *vetor = dinamicVector(n);
    for(int i = 0; i < n; i++){
        printf("Digite o %do numero: ", i+1);
        scanf("%d", &vetor[i]);
    }
    printValues(vetor, n);

    memoryFree(vetor);
    return 0;
}
