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
void *showTeam(int i, char* times[8][2]);
void *showTeamNames(char *times[8][2]);
void *iniciarCampeonato(char *times[8][2]);
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

    iniciarCampeonato(times);

    return 0;
}

// Functions
void *showTeam(int i, char* times[8][2]){
    printf("\n\tJOGO %d\n", i+1);
    printf("\n%s - %s\n", times[i][0], times[i][1]);
    printf("_______________________\n");
}

void *showTeamNames(char *times[8][2]){
    int i;
    printf("=====================\n");
    printf(" TIMES DO CAMPEONATO \n");
    printf("---------------------\n");
    for(i = 0; i < 8; i++){
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

void *iniciarCampeonato(char *times[8][2]) {
    int placar[8][2];
    int i, e, winnerAmount, draws;
    char *winners[8];


    for(i = 0; i < 8; i++){
        clear();
        showTeamNames(times);
        showTeam(i, times);

        for(e = 0; e < 2; e++){
            printf("Digite o placar do time %d: ", e+1);
            scanf("%d", &placar[i][e]);
        }

        if(placar[i][0] > placar[i][1]){
            //printf("VENCEDOR: %s\n", times[i][0]);
            winners[i] = times[i][0];
            winnerAmount += 1;

        }else if(placar[i][0] == placar[i][1]){
            do {
                printf("\nEMPATE: %s - %s\n", times[i][0], times[i][1]);
                draws += 1;
                printf("======= DESEMPATE =======\n");
                for(e = 0; e < 2; e++){
                    printf("Digite os penaltis do time %d: ", e+1);
                    scanf("%d", &placar[i][e]);
                }
                if(placar[i][0] > placar[i][1]){
                    //printf("\nVENCEDOR: %s\n", times[i][0]);
                    winners[i] = times[i][0];
                    winnerAmount += 1;
                }else if(placar[i][0] < placar[i][1]){
                    winners[i] = times[i][1];
                    winnerAmount += 1;
                    //printf("\nVENCEDOR: %s\n", times[i][1]);
                }else {
                    draws += 1;
                }
            }while(placar[i][0] == placar[i][1]);

        }else {
            //printf("VENCEDOR: %s\n", times[i][1]);
            winners[i] = times[i][1];
            winnerAmount += 1;
        }
    }


    printf("Quantidade de vencedores: %d\n", winnerAmount);
    printf("Quantidade de Empates: %d\n", draws);

    printf("\n====== WINNERS ======\n");
    for(i = 0; i < 8; i++){
        printf("%s\n", winners[i]);
    }
}
