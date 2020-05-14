#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
/*  1 porta-aviões (P),P = 11 blocos
    2 couraçados (C), C = 10 blocos [2][5] ou [5][2]
    3 torpedeiros (T) T = 7 blocos
    4 hidroaviões (H). H = 8 blocos H[2][4] ou [4][2]
 P {0 p p p 0
    p p p p p
    0 p p p 0}
 
 C : c c c c c
     c c c c c
 
 T: 0 0 t 0 0
    t t t t t
    0 0 t 0 0
 H: h h h h
    h h h h
 
 
 */
void jogador1();
void jogador2();
void instrucoes();

//sobre o relogio/cronometro

struct relogio{
    int hora;
    int minuto;
    int segundo;
};

void atualizar(struct relogio *t){
    t->segundo++;
    
    if(t->segundo == 60){
        t->segundo = 0;
        t->minuto++;
    }
    if(t->minuto == 60){
        t->minuto = 0;
        t->hora++;
    }
    if(t->hora == 24){
        t->hora = 0;
    }
    sleep(1000);
}
void mostrarRelogio(struct relogio *t){
    printf("%d:%d:%d\n", t->hora, t->minuto, t->segundo);
}
//cabou


void inicio(){
    int x;
    printf("[1] 1 Jogador\n");
    printf("[2] 2 Jogadores\n");
    printf("[3] Instruções\n");
    printf("\n");
    scanf("%d", &x);
    switch(x){
        case 1: jogador1();
        case 2: jogador2();
        case 3: instrucoes();
    }
}


void inicializaTabuleiro(int tabuleiro[][16])
{
    int linha, coluna;
    for(linha=0 ; linha < 16 ; linha++ )
        for(coluna=0 ; coluna < 16 ; coluna++ )
            tabuleiro[linha][coluna]=-1;
}

//A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P = 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16



void mostraTabuleiroJogador(int tabuleiro[][16]){
    
    int linha, coluna, jogador;
    char barco;
    
    printf("|\tA \tB \tC \tD \tE \tF \tG \tH \tI \tJ \tK \tL \tM \tN \tO \tP |");
    printf("\n");
    
    for(linha=0; linha < 16; linha++){
        printf("|%d|", linha+1);
        for(coluna=0; coluna < 16; coluna++ ){
            if(tabuleiro[linha][coluna]==-1){
                printf(" \t ");
            }else if(tabuleiro[linha][coluna]==0){
                printf("\t *");
            }else if(tabuleiro[linha][coluna]==1){
                printf("%c%d", barco, jogador);
            }
            
        }
        printf("\n");
    }
    
}

/* rascunho de como serao escolhidos as posicoes do bichinho
RAND_MAX=16
void preenche(int tabuleiro[][16], int x){
    //P
    switch(rand()%4){
        case 1:{
        P[5][3] = {0 p p p 0
                   p p p p p
                   0 p p p 0}
 
        int *p = &P[0][0] + (i-k)*3 + j-b;
        int k,b = rand();
 
    for(int i=k;i<k+5;i++)
        for(int j=b;j<b+3;j++)
            tabuleiro[i][j] = p;
            p++;
 }
 case 2:{
 P[3][5] = {0 p p p 0
 p p p p p
 0 p p p 0}
 
 int *p = &P[0][0] + (i-k)*5 + j-b;
 int k,b = rand();
 
 for(int i=k;i<k+3;i++)
 for(int j=b;j<b+5;j++)
 tabuleiro[i][j] = p;
 p++;
 }
            
    }
    
    
}
TA PODRE ESQUECE

*/
void aleatorizaTabuleiro (int tabuleiro[][16]){ //coloca os barquinhos em posicoes aleatorias no tabuleiro
    
    
    
}

void pow(linha, coluna){
    int posTiro[2];
    scanf("%c%d", &linha, &coluna);
    posTiro[0]=linha;
    posTiro[1]=coluna;
}
int acertasse(int posTiro[2], posicao navio){
    if (posicao do tiro == posicao aleatorias do navio)
        return 1;
        }
return 0;
}
void alterarTabuleiro(posTiro[2], posicao navio, int tabuleiro[][16]){
    if(acertasse(posicao tiro, posicao navio))
        tabuleiro[posTiro[0]][posTiro[1]] = 1;
    else
        tabuleiro[posTiro[0]][posTiro[1]] = 0;
}


int main(int argc, const char * argv[]) {
   

    
    
    return 0;
}
/*
incio()
 jogador1(){
 1 inicializaTabuleiro(int J1[][16])
 2 inicializaTabuleiro(int J2[][16])
 
 looping de 3-12
 
 3 mostraTabuleiro(int J1[][16])
 4 aleatorizaTabuleiro(int J1[][16])
 5 pow(linha, coluna)
 6 alterarTabuleiro(posicao navios, posicao tiro, int J1[][16])
 7 mostraTabuleiro(int J1[][16])
 
 8 mostraTabuleiro(int J2[][16])
 9 aleatorizaTabuleiro(int J2[][16])
 10 computador da o pow
 11 alterarTabuleiro(posicao navios, posicao tiro, int J2[][16])
 12 mostraTabuleiro(int J2[][16])
 }
 
 jogador2(){
 1 inicializaTabuleiro(int J1[][16])
 2 inicializaTabuleiro(int J2[][16])
 
 looping de 3-12
 
 3 mostraTabuleiro(int J1[][16])
 4 aleatorizaTabuleiro(int J1[][16])
 5 pow(linha, coluna)
 6 alterarTabuleiro(posicao navios, posicao tiro, int J1[][16])
 7 mostraTabuleiro(int J1[][16])

 8 mostraTabuleiro(int J2[][16])
 9 aleatorizaTabuleiro(int J2[][16])
 10 pow(linha, coluna)
 11 alterarTabuleiro(posicao navios, posicao tiro, int J2[][16])
 12 mostraTabuleiro(int J2[][16])
 
 }
 
 */
