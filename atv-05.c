#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
void clear();


int main(){
    int placar[8][2];
    int i, e, winnerAmount, draws;
    char *winners[8];
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

    for(i = 0; i < 8; i++){
        clear();
        showTeamNames(times);
        showTeam(i, times);

        for(e = 0; e < 2; e++){
            printf("Digite o placar do time %d: ", e+1);
            scanf("%d", &placar[i][e]);
        }
    }

    printf("\n====== PLACAR ======\n");
    for(i = 0; i < 8; i++){

        if(placar[i][0] > placar[i][1]){
            winnerAmount += 1;

        }else if(placar[i][0] == placar[i][1]){
            draws += 1;
        }else {
            winnerAmount += 1;
            // TIME 2 GANHOU
        }
    }

    printf("Quantidade de vencedores: %d\n", winnerAmount);
    printf("Quantidade de Empates: %d\n", draws);


    /*printf("______________________________\n");
    printf("JOGO %d:\nTIME 1:%d\nTIME 2: %d\n", i, placar[i][0], placar[i][1]);
    printf("______________________________\n");*/


    return 0;
}

// Functions

void *showTeam(int i, char* times[8][2]){
    printf("\n%s - %s\n", times[i][0], times[i][1]);
    printf("_______________________\n");
}

void *showTeamNames(char *times[8][2]){
    int i;
    printf("=====================\n");
    printf("        TIMES        \n");
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

