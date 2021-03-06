#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
/*  1 porta-aviões (P),P = 11 blocos [3][5] ou [5][3]
 2 couraçados (C), C = 10 blocos [2][5] ou [5][2]
 3 torpedeiros (T) T = 7 blocos [3][5] ou [5][3]
 4 hidroaviões (H). H = 8 blocos H[2][4] ou [4][2]
 pta[3][5] = {{0, p, p, p, 0},
 {p, p, p, p, p},
 {0, p, p, p, 0}};
 
 cou[2][5] = {{c, c, c, c, c},
 {c, c, c, c, c}};
 
 tor[3][5] = {{0, 0, t, 0, 0},
 {t, t, t, t, t},
 {0, 0, t, 0, 0}};
 
 hdv[2][4] = {{h, h, h, h},
 {h, h, h, h}};
 */

void jogador1();
void jogador2();
void instrucoes();

struct coordenadas{
    int cord[2];
};
struct posicoes{
    struct coordenadas posP[11];
    struct coordenadas posC1[10]; struct coordenadas posC2[10];
    struct coordenadas posT1[7]; struct coordenadas posT2[7]; struct coordenadas posT3[7];
    struct coordenadas posH1[8]; struct coordenadas posH2[8]; struct coordenadas posH3[8]; struct coordenadas posH4[8];
}pos1, pos2;
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
    sleep(1);
}
void mostrarRelogio(struct relogio *t){
    printf("%d:%d:%d\n", t->hora, t->minuto, t->segundo);
}
//cabou


void inicio(){ //como inicia o jogo, basicamente o painel de inicio
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


void inicializaTabuleiro(int tabuleiro[][16]) //inicializa uma matris que sera um dos tabuleiro preenchendo tds as "casas"com -1
{
    int linha, coluna;
    for(linha=0 ; linha < 16 ; linha++ )
        for(coluna=0 ; coluna < 16 ; coluna++)
            tabuleiro[linha][coluna]=-1;
}

void mostraTabuleiroJogador1(int tabuleiro[][16]){ //como o tabuleiro vai aparecer na tela do jogador 1 ou seja eh o tab do jogador 2
    
    int linha, coluna;
    
    printf("|\tA \tB \tC \tD \tE \tF \tG \tH \tI \tJ \tK \tL \tM \tN \tO \tP |");
    printf("\n");
    
    for(linha=0; linha < 16; linha++){
        printf("|%d|", linha+1);
        for(coluna=0; coluna < 16; coluna++ ){
            if(tabuleiro[linha][coluna]==-1){
                printf(" \t ");
            }
            else if(tabuleiro[linha][coluna]==0){
                printf("\t *");
            }
            else if(tabuleiro[linha][coluna]==121){
                printf("P1");
            }
            else if(tabuleiro[linha][coluna]==100){
                printf("H1");
            }
            else if(tabuleiro[linha][coluna]==49){
                printf("T1");
            }
            else if(tabuleiro[linha][coluna]==64){
                printf("C1");
            }
        }
        printf("\n");
    }
    
}
void mostraTabuleiroJogador2(int tabuleiro[][16]){
    
    int linha, coluna;
    
    printf("|\t\tA \tB \tC \tD \tE \tF \tG \tH \tI \tJ \tK \tL \tM \tN \tO \tP |");
    printf("\n");
    
    for(linha=0; linha < 16; linha++){
        printf("%d", linha+1);
        for(coluna=0; coluna < 16; coluna++ ){
            if(tabuleiro[linha][coluna]==-1){
                printf("\t");
            }
            else if(tabuleiro[linha][coluna]==0){
                printf("\t*");
            }
            else if(tabuleiro[linha][coluna]==121){
                printf("P2");
            }
            else if(tabuleiro[linha][coluna]==100){
                printf("H2");
            }
            else if(tabuleiro[linha][coluna]==49){
                printf("T2");
            }
            else if(tabuleiro[linha][coluna]==64){
                printf("C2");
            }
            
            
        }
        printf("\n");
    }
    
}

/* rascunho de como serao escolhidos as posicoes do bichinho
 ainda nao sei bem como colocar as embarcacoes em cada um dos tabuleiros, mas pensei em criar uma matriz pra cada tipo de barco que guarda as coordenadas x, y da peça,
 dai depois de sortear a posição do primeiro elemento usavaria alguma recursão pra preencher o resto do tabuleiro de acordo com o formato de cada peça.
 struct posicoes{
 int posP[2][11];
 int posC1[2][10];int posC2[2][10];
 int posT1[2][7]; int posT2[2][7]; int posT3[2][7];
 int posH1[2][8]; int posH2[2][8]; int posH3[2][8]; int posH4[2][8];
 }pos1, pos2;
 
 
void aleatorizaTabuleiroJ1 (struct posicoes pos1){ //coloca os barquinhos em posicoes aleatorias no tabuleiro
  
        if(){
            posP[0][0] = x;
            posP[0][1] = x+1;
            posP[0][2] = x+2;
            posP[1][0] = y;
            posP[1][1] = y;
            posP[1][2] = y;
            
            posP[0][3] = x-1;
            posP[0][4] = x;
            posP[0][5] = x+1;
            posP[0][6] = x+2;
            posP[0][7] = x+3;
            posP[1][3] = y+1;
            posP[1][4] = y+1;
            posP[1][5] = y+1;
            posP[1][6] = y+1;
            posP[1][7] = y+1;
            
            posP[0][8] = x;
            posP[0][9] = x+1;
            posP[0][10] = x+2;
            posP[1][8] = y+2;
            posP[1][9] = y+2;
            posP[1][10] = y+2;
            
            
            
            
            
        }
        
        
    }
    
    
}

void pow(linha, colunaLetra){ //tipo aqui eh basicamente a posição do tiro, eu quis colocar num vetor pra poder comparar em outra função a posição do tiro e das embarcações
    int posTiro[2], coluna;
    scanf("%c%d", &colunaLetra, &linha);
    posTiro[0]=linha;
    switch(colunaLetra){ //essa palhaçada aqui é pq a pessoa vai dar o Pow numa casa tipo E2, ai eu queria dar a esse E um numero de linha na matriz tabuleiro
        case 'A': coluna = 0;
        case 'B': coluna = 1;
        case 'C': coluna = 2;
        case 'D': coluna = 3;
        case 'E': coluna = 4;
        case 'F': coluna = 5;
        case 'G': coluna = 6;
        case 'H': coluna = 7;
        case 'I': coluna = 8;
        case 'J': coluna = 9;
        case 'K': coluna = 10;
        case 'L': coluna = 11;
        case 'M': coluna = 12;
        case 'N': coluna = 13;
        case 'O': coluna = 14;
        case 'P': coluna = 15;
    }
    posTiro[1]=coluna;
}
*/
int acertasse(int posTiro[2], struct posicoes posi[]){// essa funcao vai ser basicamente pra verificar se o jogador acertou o tiro 1 pra vdd e 0 p falso, que eu usei dentro da funcao que altera o tab
    
    
  
        for(int p=0; p<11; p++){
            if (posTiro[0] == posi->posP[p].cord[0]&& posTiro[1] == posi->posP[p].cord[1])
                return 1;
            else if(posTiro[0] == posi->posC1[p].cord[0]&& posTiro[1] == posi->posC1[p].cord[1])
                return 1;
            else if(posTiro[0] == posi->posC2[p].cord[0]&& posTiro[1] == posi->posC2[p].cord[1])
                return 1;
            else if(posTiro[0] == posi->posH1[p].cord[0]&& posTiro[1] == posi->posH1[p].cord[1])
                return 1;
            else if(posTiro[0] == posi->posH2[p].cord[0]&& posTiro[1] == posi->posH2[p].cord[1])
                return 1;
            else if(posTiro[0] == posi->posH3[p].cord[0]&& posTiro[1] == posi->posH3[p].cord[1])
                return 1;
            else if(posTiro[0] == posi->posH4[p].cord[0]&& posTiro[1] == posi->posH4[p].cord[1])
                return 1;
            else if(posTiro[0] == posi->posT1[p].cord[0]&& posTiro[1] == posi->posT1[p].cord[1])
                return 1;
            else if(posTiro[0] == posi->posT2[p].cord[0]&& posTiro[1] == posi->posT2[p].cord[1])
                return 1;
            else if(posTiro[0] == posi->posT3[p].cord[0]&& posTiro[1] == posi->posT3[p].cord[1])
                return 1;
            
    }
    return 0;
    
}
    void alterarTabuleiro1(int posTiro[2], int tabuleiro[][16]){ //caso acerte ou nao o tab ele vai ser alterado pra por um * ou a embarcação dai e existencia dessa funcao
    if(acertasse(posTiro, pos1.posP))
        tabuleiro[posTiro[0]][posTiro[1]] = 121;
    else if(acertasse(posTiro, pos1.posH1)|| acertasse(posTiro, pos1.posH2)||acertasse(posTiro, pos1.posH3)||acertasse(posTiro, pos1.posH4))
        tabuleiro[posTiro[0]][posTiro[1]] = 64;
    else if(acertasse(posTiro, pos1.posC1)|| acertasse(posTiro, pos1.posC2))
        tabuleiro[posTiro[0]][posTiro[1]] = 100;
    else if(acertasse(posTiro, pos1.posT1)||acertasse(posTiro, pos1.posT2)||acertasse(posTiro, pos1.posT3))
        tabuleiro[posTiro[0]][posTiro[1]] = 49;
    else
        tabuleiro[posTiro[0]][posTiro[1]] = 0;
}


int main(int argc, const char * argv[]) {
    
    
    
    
    return 0;
}
/* aqui é meio que a ordem que as funções vão ser chamadas pra cada rodada de jogo
 incio()
 jogador1(){
 1 inicializaTabuleiro1(int J1[][16])
 2 inicializaTabuleiro2(int J2[][16])
 
 looping de 3-12
 
 3 mostraTabuleiro1(int J1[][16])
 4 aleatorizaTabuleiro(int J1[][16])
 5 pow(linha, coluna)
 6 alterarTabuleiro(posicao navios, posicao tiro, int J1[][16])
 7 mostraTabuleiro1(int J1[][16])
 
 8 mostraTabuleiro2(int J2[][16])
 9 aleatorizaTabuleiro(int J2[][16])
 10 computador da o pow
 11 alterarTabuleiro(posicao navios, posicao tiro, int J2[][16])
 12 mostraTabuleiro2(int J2[][16])
 }
 
 jogador2(){
 1 inicializaTabuleiro1(int J1[][16])
 2 inicializaTabuleiro2(int J2[][16])
 
 looping de 3-14
 
 3 mostraTabuleiro1(int J1[][16])
 4 aleatorizaTabuleiro(int J1[][16])
 5 pow(linha, coluna)
 6 alterarTabuleiro(posicao navios, posicao tiro, int J1[][16])
 7 mostraTabuleiro1(int J1[][16])
 8 void mostrarRelogio(struct relogio *t)
 
 9 mostraTabuleiro2(int J2[][16])
 10 aleatorizaTabuleiro(int J2[][16])
 11 pow(linha, coluna)
 12 alterarTabuleiro(posicao navios, posicao tiro, int J2[][16])
 13 mostraTabuleiro2(int J2[][16])
 14 void mostrarRelogio(struct relogio *t)
 }
 */

