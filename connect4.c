#include <stdio.h>
#include <stdlib.h>

void zeraTabuleiro(int tabuleiro[6][7]){
    
    for (int i = 0; i < 6; i++) { 
            
        for (int j = 0; j < 7; j++) {
                    
                    tabuleiro[i][j] = 0;
                    
        }
                
    }

}

int main() {
    
    int tabuleiro[6][7], linha, pecaJogada, comecoLinha, comecoColuna; 
    
    int jogador = 1, vitoriasJogador1 = 0, vitoriasJogador2 = 0, novamente = 1,  final = 0, totalJogadas = 0, sequencia = 0;


    while (novamente == 1){ //Enquanto novamente tiver valor 1, o jogo continua, e varias rodadas vão acontecendo
        
        zeraTabuleiro(tabuleiro); //Zera o tabuleiro
        
        final = 0;
        
        totalJogadas = 0;
        
        while ((final == 0) && (totalJogadas < 42)) { //Enquanto final for falso e o tabuleiro nao estiver cheio (42)
            
            printf("\n\n\n1 - 2 - 3 - 4 - 5 - 6 - 7\n-------------------------\n");
            
            for (int i = 0; i < 6; i++) {
                
                for (int j = 0; j < 7; j++) {
                    
                    printf("%d   ", tabuleiro[i][j]);
                    
                }
                
                printf("\n\n");
                
            }
            
            printf("\n");
            
            printf("Jogador %d, e sua vez. Selecione uma coluna (1-7): ", jogador); //nro do jogador
            
            scanf("%d", &pecaJogada);
            
            pecaJogada--; // Diminui um numero pra matriz ficar 0-6
            
            if ((pecaJogada >= 0) && (pecaJogada < 7) && (tabuleiro[0][pecaJogada] == 0)) { //Confere se a coluna é válida
            //Se a coluna escolhida for maior/igual a 0 e menor/igual a 6, e o espaço selecionado estiver vazio, coloca o nro do jogador na posição
            
                for (linha = 5; linha >= 0; linha--) { //Procura uma posição vazia na coluna e coloca o nro do jogador
                
                    if (tabuleiro[linha][pecaJogada] == 0) {
                        
                        tabuleiro[linha][pecaJogada] = jogador;
                        
                        break; //impede de seguir colocando o nro do jogador na coluna toda
                        
                    }
                    
                }
                
                totalJogadas++;
                
                sequencia = 0;
                
                for (int j = 0; j < 7; j++) { //Procura uma sequencia de 4 peças iguais na horizontal
                
                    if (tabuleiro[linha][j] == jogador) {
                        
                        sequencia++;
                        
                        if (sequencia == 4) {
                            
                            printf("\n\n\n1 - 2 - 3 - 4 - 5 - 6 - 7\n-------------------------\n"); //Imprime o tabuleira denovo
                            
                            for (int i = 0; i < 6; i++) {
                                
                                for (int j = 0; j < 7; j++) {
                                    
                                    printf("%d   ", tabuleiro[i][j]);
                                    
                                }
                                
                                printf("\n\n");
                                
                            }
                            
                            printf("\n");
                            
                            printf("\nO vencedor e...JOGADOR %d!\n", jogador);
                            
                            if (jogador == 1) {
                                
                                vitoriasJogador1++;
                                
                            } else {
                                
                                vitoriasJogador2++;
                                
                            }
                            
                            final = 1; 
                            
                            break; //Termina a rodada após sequencia chegar em 4 e final virar 1
                            
                        }
                        
                    } else {
                        
                        sequencia = 0; //Zera a variavel sequencia
                        
                    }
                    
                }
                
                sequencia = 0;
                
                for (int i = 0; i < 6; i++) { //Procura uma sequencia de 4 peças iguais na vertical
                
                    if (tabuleiro[i][pecaJogada] == jogador) {
                        
                        sequencia++;
                        
                        if (sequencia == 4) {
                            
                            printf("\n1 - 2 - 3 - 4 - 5 - 6 - 7\n-------------------------\n");
                            
                            for (int i = 0; i < 6; i++) {
                                
                                for (int j = 0; j < 7; j++) {
                                    
                                    printf("%d   ", tabuleiro[i][j]);
                                    
                                }
                                
                                printf("\n\n");
                                
                            }
                            
                            printf("\n");
                            
                            printf("\nO vencedor e...JOGADOR %d!\n", jogador);

                            if (jogador == 1) {
                                
                                vitoriasJogador1++;
                                
                            } else {
                                
                                vitoriasJogador2++;
                                
                            }
                            
                            final = 1;
                            
                            break;
                            
                        }
                        
                    } else {
                        
                        sequencia = 0;
                        
                    }
                    
                }
                
                //Procura uma sequencia de 4 peças iguais na diagonal para o topo esquerdo do tabuleiro
                sequencia = 0;
                
                comecoLinha = linha; //Recebe o valor da linha e da coluna e vai "subindo" no tabuleiro a cada iteração
                
                comecoColuna = pecaJogada; 
                
                while ((comecoLinha > 0) && (comecoColuna > 0)) { //Vai diminuindo até ficar 0 (não ter nenhuma peça)
                
                    comecoLinha--;
                    
                    comecoColuna--;
                    
                }
                
                while ((comecoLinha < 6) && (comecoColuna < 7)) {
                    
                    if (tabuleiro[comecoLinha][comecoColuna] == jogador) { //Se o espaço tiver um numero 1 ou 2
                        
                        sequencia++;
                        
                        if (sequencia == 4) {
                            
                            printf("\n1 - 2 - 3 - 4 - 5 - 6 - 7\n-------------------------\n");
                            
                            for (int i = 0; i < 6; i++) {
                                
                                for (int j = 0; j < 7; j++) {
                                    
                                    printf("%d   ", tabuleiro[i][j]);
                                    
                                }
                                
                                printf("\n\n");
                                
                            }
                            
                            printf("\n");
                            
                            printf("\nO vencedor e...JOGADOR %d!\n", jogador);
                            

                            if (jogador == 1) {
                                
                                vitoriasJogador1++;
                                
                            } else {
                                
                                vitoriasJogador2++;
                                
                            }
                            
                            final = 1;
                            
                            break;
                            
                        }
                        
                    } else {
                        
                        sequencia = 0;
                        
                    }
                    
                    comecoLinha++;
                    
                    comecoColuna++;
                    
                }
                
                //Procura uma sequencia de 4 peças iguais na diagonal para o topo direito do tabuleiro
                sequencia = 0;
                
                comecoLinha = linha;
                
                comecoColuna = pecaJogada;
                
                while ((comecoLinha > 0) && (comecoColuna < 6)) {
                    
                    comecoLinha--;
                    
                    comecoColuna++;
                    
                }
                
                while ((comecoLinha < 6) && (comecoColuna >= 0)) {
                    
                    if (tabuleiro[comecoLinha][comecoColuna] == jogador) {
                        
                        sequencia++;
                        
                        if (sequencia == 4) { //Imprime o tabuleiro denovo
                        
                            printf("\n1 - 2 - 3 - 4 - 5 - 6 - 7\n-------------------------\n");
                            
                            for (int i = 0; i < 6; i++) {
                                
                                for (int j = 0; j < 7; j++) {
                                    
                                    printf("%d   ", tabuleiro[i][j]);
                                    
                                }
                                
                                printf("\n\n");
                                
                            }
                            
                            printf("\n");
                            
                            printf("\nO vencedor e...JOGADOR %d!\n", jogador);
                            
                            if (jogador == 1) {
                                
                                vitoriasJogador1++;
                                
                            } else {
                                
                                vitoriasJogador2++;
                                
                            }
                            
                            final = 1;
                            
                            break;
                            
                        }
                        
                    } else {
                        
                        sequencia = 0;
                        
                    }
                    
                    //Passa pra proxima posição na diagonal
                    comecoLinha++; 
                    
                    comecoColuna--;
                    
                }
                
                if (jogador == 1){ //Troca de jogador
                
                    jogador = 2;
                    
                }else{
                    
                    jogador = 1;
                    
                }
                
            } else {
                
                printf("\nERRO! TENTE NOVAMENTE.\n"); //Coluna inválida
                
            }
            
        }

        if ((final == 0) && (totalJogadas == 42)) { // Imprime o tabuleiro uma ultima vez com o resultado final
            
            printf("\n1 - 2 - 3 - 4 - 5 - 6 - 7\n-------------------------\n");
            
            for (int i = 0; i < 6; i++) {
                
                for (int j = 0; j < 7; j++) {
                    
                    printf("%d   ", tabuleiro[i][j]);
                    
                }
                
                printf("\n\n");
                
            }
            
            printf("\n");
            
            printf("EMPATE!\n"); //Se atingir o nro maximo de jogadas sem ganhador
            
        }
        
        printf("\nDeseja jogar novamente? (1 - SIM, 0 - NAO): ");
        
        scanf("%d", &novamente);
        
        while ((novamente < 0) || (novamente > 1)){
            
            printf("\nERRO! TENTE NOVAMENTE (1 - SIM, 0 - NAO): ");
            
            scanf("%d", &novamente);
            
        }
        
    } 

    printf("\nVITORIAS DO JOGADOR 1: %d\n", vitoriasJogador1);
    
    printf("\nVITORIAS DO JOGADOR 2: %d\n", vitoriasJogador2);

}