#include <stdio.h>
#include <stdlib.h>

/*
1) Faça um programa que leia um valor n e crie
dinamicamente um vetor de n elementos e passe
esse vetor para uma função que vai ler os elementos
desse vetor. Depois, no programa principal,
o vetor preenchido deve ser impresso.
Além disso, antes de finalizar o programa,
deve-se liberar a área de memória alocada.
*/

void readValues(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("Digite o %do numero: ", i+1);
        scanf("%d", &vetor[i]);
    }
}


int main (){
    int n;
    printf("Digite um valor 'n': ");
    scanf("%d", &n);

    int *vetor = (int*)malloc(sizeof(int) * n);

    readValues(vetor, n);
    for(int i = 0; i < n; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    free(vetor);
    return 0;
}
