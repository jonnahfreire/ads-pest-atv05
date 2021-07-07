#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    ADS S2 - CAMPUS CANINDÉ
    DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
    PROF: MANOEL LOPES
    DUPLA: JONAS DE SOUSA FREIRE, JESSYLENE SOARES MACIEL

    CAMPEONATO DE FUTEBOL MATA-MATA
*/

// Function Prototypes
void *showTeam(int i, char* times[8][2], int etapa);
void *showTeamNames(char *times[8][2]);
void *iniciarCampeonato(char *times[8][2], int etapa);
void clear();


int main(){
    char *times[8][2] = {
        {"Brasil", "Finlandia"},
        {"Canada", "Belgica"},
        {"Mexico", "Argentina"},
        {"Noruega", "Russia"},
        {"EUA", "Marrocos"},
        {"Camaroes", "Inglaterra"},
        {"Irlanda", "Chile"},
        {"Peru", "Colombia"}
    };
    int etapa = 1;
    iniciarCampeonato(times, etapa);

    return 0;
}

// Functions
void *showTeam(int i, char* times[8][2], int etapa){
    printf("\n  JOGO %d - ETAPA %d\n", i+1, etapa);
    times[i][0] != '\0' &&
    printf("\n%s - %s\n", times[i][0], times[i][1]);
    printf("_______________________\n");
}

void *showTeamNames(char *times[8][2]){
    int i;
    printf("=====================\n");
    printf(" TIMES DO CAMPEONATO \n");
    printf("---------------------\n");
    for(i = 0; i < 8; i++){
        times[i][0] != '\0' &&
        printf("%s - %s\n", times[i][0], times[i][1]);
    }
    printf("_____________________\n");
}

void clear(){
    #ifdef _WIN32
	    system("cls");
	#else
        #if __linux__
            system("clear");
        #endif
    #endif
}

int getTimesLength(char *times[8][2]) {
    int i, length;
    for(i = 0; i < 8; i++){
        if((times[i][0] && times[i][1] != '\0'))
           length++;
    }
    return length;
}

void *iniciarCampeonato(char *times[8][2], int etapa) {
    unsigned int placar[8][2];
    /* = {
        {5, 4},
        {3, 4},
        {2, 2},
        {3, 3},
        {1, 2},
        {3, 6},
        {1, 2},
        {2, 3},
    };*/
    int i, e, winnerAmount, draws;
    char *winners[8];

    for(i = 0; i < 8; i++){
        if((times[i][0] != '\0') && (times[i][1] != '\0')){
            clear();
            showTeamNames(times);
            showTeam(i, times, etapa);

            for(e = 0; e < 2; e++){
                ((times[i][0] != '\0') && (times[i][1] != '\0')) &&
                printf("Digite o placar do time %d: ", e+1);
                scanf("%d", &placar[i][e]);
            }

            if(placar[i][0] > placar[i][1]){
                winners[i] = times[i][0];
                winnerAmount += 1;

            }else if(placar[i][0] == placar[i][1]){
                do {
                    if(times[i][0] == '\0') break;
                    printf("\nEMPATE: %s - %s\n", times[i][0], times[i][1]);
                    draws += 1;
                    printf("======= DESEMPATE =======\n");
                    for(e = 0; e < 2; e++){
                        printf("Digite os penaltis do time %d: ", e+1);
                        scanf("%d", &placar[i][e]);
                    }
                    if(placar[i][0] > placar[i][1]){
                        winners[i] = times[i][0];
                        winnerAmount += 1;
                    }else if(placar[i][0] < placar[i][1]){
                        winners[i] = times[i][1];
                        winnerAmount += 1;
                    }else {
                        draws += 1;
                    }
                }while(placar[i][0] == placar[i][1]);

            }else {
                winners[i] = times[i][1];
                winnerAmount += 1;
            }
        }

    }


    //printf("Quantidade de vencedores: %d\n", winnerAmount);
    //printf("Quantidade de Empates: %d\n", draws);

    printf("\n====== VENCEDORES ETAPA %d ======\n", etapa);
    for(i = 0; i < 8; i++){
        printf("%s\n", winners[i]);
    }

    etapa += 1;

    for(i = 0; i < 8; i++){
        for(e = 0; e < 2; e++){
            times[i][e] = '\0';
        }
    }


    int a=0;
    for(i = 0; i < 8; i+=2){
        for(e = 0; e < 2; e++){
            times[i][e] = (e == 1) ? winners[i+1] : winners[i];
            a++;
        }
    }
    printf("\n\nNOVOS TIMES A JOGAR\n");

    for(i = 0; i < 8; i++){
        times[i][0] != '\0' && printf("%s - %s\n", times[i][0], times[i][1]);
    }

    for(i = 0; i < 8; i++) winners[i] = '\0';

    iniciarCampeonato(times, etapa);

}
