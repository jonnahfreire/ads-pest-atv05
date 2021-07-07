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
void showFinalists(char *times[8][2], unsigned int placar[8][2]);
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
    char newChampionship;
    int etapa = 1;

    do {
        iniciarCampeonato(times, etapa);

        printf("Novo Campeonato? [S/N]: ");
        scanf("%c", &newChampionship);
    }while(newChampionship);

    printf("\n\nBye!!\n\n");

    return 0;
}



// -------------------------- Functions -----------------------------
void *showTeam(int i, char* times[8][2], int etapa){
    if(etapa <= 3){
        printf("\n  JOGO %d - ETAPA %d\n", i+1, etapa);
        times[i][0] != '\0' &&
        printf("\n%s - %s\n", times[i][0], times[i][1]);
        printf("_______________________\n");
    }else if(etapa == 4){
        printf("\n    JOGO FINAL\n");
        times[i][0] != '\0' &&
        printf("\n%s - %s\n", times[i][0], times[i][1]);
        printf("_______________________\n");
    }
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


void showFinalists(char *times[8][2], unsigned int placar[8][2]){
    clear();
    printf("==========================\n");
    printf("*CAMPEAO: %s\n*VICE-CAMPEAO: %s\n",
           times[0][0], times[0][1]);

    (placar[0][0] > placar[0][1]) &&
    printf("*PLACAR: %d x %d\n",
           placar[0][0], placar[0][1]);

    (placar[0][0] < placar[0][1]) &&
    printf("*PLACAR: %d x %d\n",
           placar[0][1], placar[0][0]);
    printf("==========================\n");
}

void *iniciarCampeonato(char *times[8][2], int etapa) {
    unsigned int placar[8][2];
    int i, e, c, a=0, winnerAmount;
    char *winners[8];

    for(i = 0; i < 8; i++){
        if((times[i][0] != '\0') && (times[i][1] != '\0')){
            clear();
            showTeamNames(times);
            showTeam(a, times, etapa);
            a++;

            for(e = 0; e < 2; e++){
                if((times[i][0] != '\0') && (times[i][1] != '\0')) {
                    printf("Digite o placar do time %d: ", e+1);
                    scanf("%d", &placar[i][e]);
                }
            }

            if(placar[i][0] > placar[i][1]){
                if((i > 0) && (times[i-1][0] == NULL)) winners[i-1] = times[i][0];
                else winners[i] = times[i][0];
                winnerAmount += 1;

            }else if(placar[i][0] == placar[i][1]){
                do {
                    if(times[i][0] == '\0') break;
                    printf("\nEMPATE: %s - %s\n", times[i][0], times[i][1]);

                    printf("======= DESEMPATE =======\n");
                    for(e = 0; e < 2; e++){
                        printf("Digite os penaltis do time %d: ", e+1);
                        scanf("%d", &placar[i][e]);
                    }
                    if(placar[i][0] > placar[i][1]){
                        if((i > 0) && (times[i-1][0] == NULL)) winners[i-1] = times[i][0];
                        else winners[i] = times[i][0];
                        winnerAmount += 1;

                    }else if(placar[i][0] < placar[i][1]){
                        if((i > 0) && (times[i-1][0] == NULL)) winners[i-1] = times[i][1];
                        else winners[i] = times[i][1];
                        winnerAmount += 1;
                    }
                }while(placar[i][0] == placar[i][1]);

            }else if (placar[i][0] < placar[i][1]){
                if((i > 0) && (times[i-1][0] == NULL)) winners[i-1] = times[i][1];
                else winners[i] = times[i][1];
                winnerAmount += 1;
            }
        }
    }


    if(etapa < 4){
        for(i = 0; i < winnerAmount; i++){
            for(e = 0; e < 2; e++){
                times[i][e] = '\0';
            }
        }
        c = 0;
        for(i = 0; i < winnerAmount; i+=2){
            for(e = 0; e < 2; e++)
                times[c][e] = (e == 1)
                ? winners[i+1] : winners[i];
            c++;
        }

        for(i = 0; (winners[i] != NULL); i++) winners[i] = '\0';
    }

    if(etapa == 4) {
        showFinalists(times, placar);
    }

    etapa += 1;
    etapa < 5 && iniciarCampeonato(times, etapa);
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
