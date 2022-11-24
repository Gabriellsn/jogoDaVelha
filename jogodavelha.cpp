#include <iostream>
#include <stdio.h>
#include<string.h>
#include<string>
#include<conio.h>
#include <locale.h>
#include<windows.h>



using namespace std;



/* variaveis*/ 

int cont = 0, movimentaCursor, inicioJogo = 0, turno = 0, posicaoLinha= 0, posicaoColuna= 0, pontosJogador1 = 0, pontosJogador2 = 0 , vitoria = 0, reseta = 0;
char matrizMenu[2][1], matrizJogo[3][3], jogador1[20], jogador2[20], matrizPartida1[3][3], matrizPartida2[3][3], matrizPartida3[3][3], matrizVerificadora[3][3];


	/*funçoes*/
	void menuInicial(){
		printf(" # JOGO DA VELHA #\n \n");
		printf("     JOGAR\n\n");
		printf("   instruçoes\n");
		while(inicioJogo != 1 && inicioJogo != 2){
		
		if(!kbhit()){
			 movimentaCursor = getch();
			 switch(movimentaCursor){
			 	case 119:
			 		matrizMenu[0][0] = '@';
			 		matrizMenu[1][0] = ' ';
			 		system("cls");
			 		printf(" # JOGO DA VELHA #\n \n");
					printf("     %cJOGAR\n\n", matrizMenu[0][0]);
					printf("   %cinstruçoes\n",matrizMenu[1][0]);
			 	break;
			 	
			 	case 115:
			 		matrizMenu[1][0] = '@';
			 		matrizMenu[0][0] = ' ';
			 		system("cls");
			 		printf(" # JOGO DA VELHA #\n \n");
					printf("     %cJOGAR\n\n", matrizMenu[0][0]);
					printf("   %cinstruçoes\n",matrizMenu[1][0]);
				break;
				
				case 101:
					if(matrizMenu[0][0] == '@'){
						inicioJogo = 1;
					}else if(matrizMenu[1][0] == '@'){
						inicioJogo = 2;
					}
				break;
			 	}
				
			}
			
		}
		
	}
	void menuOpcoes(){
		
		
			printf("Ola, esse é um jogo da velha feito por Gabriel Lopo para um projeto da faculdade.\n");
			printf("* Para jogar é muito simples, selecione a linha e a coluna desejada *\n");
			printf("* E o sistema automaticamente marcara sua opçao :) *\n");
			printf("* lembre que o jogo é uma melhor de 3 entao nao desanime se perder uma rodada *\n");
			printf("* sua vez sempre sera sinalizada pelo seu nome e pelo simbolo que te representa sendo ele X ou O *\n");
			
	}
	void printMatriz(){
		printf("    0   1   2 \n");
			printf("   ---|---|---\n");
			printf("0  %c  | %c | %c \n", matrizJogo[0][0], matrizJogo[0][1],matrizJogo[0][2]);
			printf("   ---|---|---\n");
			printf("1  %c  | %c | %c \n", matrizJogo[1][0], matrizJogo[1][1],matrizJogo[1][2]);
			printf("   ---|---|---\n");
			printf("2  %c  | %c | %c \n", matrizJogo[2][0], matrizJogo[2][1],matrizJogo[2][2]);
	}
	void nomeJogadores(){
	
		printf("escolha o nome do jogardor 1 (X): \n");
		scanf("%s", &jogador1);
		printf("escolha o nome do jogardor 2 (O): \n");
		scanf("%s", &jogador2);
		system("cls");
	}
	void escolhendoPosicao(){
		
		printf("escolha a linha desejada: ");
		scanf("%d", &posicaoLinha);
		while(!(posicaoLinha <= 2) || !(posicaoLinha >= 0)){
			printf("valor de posiçao invalido\n");
			printf("escolha a linha desejada: ");
			scanf("%d", &posicaoLinha);
		}
		
			printf("escolha a colua desejada: ");
			scanf("%d", &posicaoColuna);
			while(!(posicaoColuna <= 2) || !(posicaoColuna >= 0)){
				printf("valor de posiçao invalido\n");
				printf("escolha a colua desejada: ");
				scanf("%d", &posicaoColuna);
		}
			if(matrizJogo[posicaoLinha][posicaoColuna] == ' '){
				if( turno % 2 == 0){
					matrizJogo[posicaoLinha][posicaoColuna] = 'X';	
				}else {
					matrizJogo[posicaoLinha][posicaoColuna] = 'O';
				}
				
				
				
			}else{
				printf("essa posicao ja esta ocupada, escolha outra\n");
				
				escolhendoPosicao();
			}
	}
	void verificaVitoria(){
	
		if((matrizJogo[0][0] == 'X' && matrizJogo[1][1] == 'X' && matrizJogo[2][2] == 'X') || 
		(matrizJogo[0][0] == 'X' && matrizJogo[0][1] == 'X' && matrizJogo[0][2] == 'X') || 
		(matrizJogo[1][0] == 'X' && matrizJogo[1][1] == 'X' && matrizJogo[1][2] == 'X') || 
		(matrizJogo[2][0] == 'X' && matrizJogo[2][1] == 'X' && matrizJogo[2][2] == 'X') ||
		(matrizJogo[0][0] == 'X' && matrizJogo[1][0] == 'X' && matrizJogo[2][0] == 'X') ||
		(matrizJogo[0][1] == 'X' && matrizJogo[1][1] == 'X' && matrizJogo[1][2] == 'X') ||
		(matrizJogo[0][2] == 'X' && matrizJogo[1][2] == 'X' && matrizJogo[2][2] == 'X')){
			 vitoria = 1;
			 pontosJogador1++;
			 
			 printf("JOGADOR %s(X) venceu essa rodada\n", jogador1);
			 printf("carregando proxima rodada...\n");
			 Sleep(5000);
			 system("cls");
			 
		}else if((matrizJogo[0][0] == 'X' && matrizJogo[1][1] == 'X' && matrizJogo[2][2] == 'X') || 
		(matrizJogo[0][0] == 'O' && matrizJogo[0][1] == 'O' && matrizJogo[0][2] == 'O') || 
		(matrizJogo[1][0] == 'O' && matrizJogo[1][1] == 'O' && matrizJogo[1][2] == 'O') || 
		(matrizJogo[2][0] == 'O' && matrizJogo[2][1] == 'O' && matrizJogo[2][2] == 'O') ||
		(matrizJogo[0][0] == 'O' && matrizJogo[1][0] == 'O' && matrizJogo[2][0] == 'O') ||
		(matrizJogo[0][1] == 'O' && matrizJogo[1][1] == 'O' && matrizJogo[1][2] == 'O') ||
		(matrizJogo[0][2] == 'O' && matrizJogo[1][2] == 'O' && matrizJogo[2][2] == 'O')){
			vitoria = 2;
			pontosJogador2++;
			
			printf("JOGADOR %s(0) venceu essa rodada\n", jogador2);
			printf("carregando proxima rodada...\n");
			Sleep(5000);
			system("cls");
			
			
			
		}
	}
	void partida(){
		system("cls");
		printMatriz();
		if( turno % 2 == 0){
			printf("Vez de %s (x)\n", jogador1);
		}else{
			printf("Vez de %s (O)\n", jogador2);
		}
		
		escolhendoPosicao();
		
		
			
		
		
		
		
	}
	void esvaziandoMatriz(){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				matrizJogo[i][j] = ' ';
			}
		}
	}
	void salvandoMatriz(){
		cont++;
		if(cont == 1){
			for(int i = 0; i < 3; i ++){
			for(int j = 0; j < 3; j++){
				matrizPartida1[i][j] = 	matrizJogo[i][j] ;
			}
		}
	}	
		if(cont == 2){
				for(int i = 0; i < 3; i ++){
				for(int j = 0; j < 3; j++){
					matrizPartida2[i][j] = 	matrizJogo[i][j] ;
				}
			}
		}
		if(cont == 3){
			for(int i = 0; i < 3; i ++){
			for(int j = 0; j < 3; j++){
				matrizPartida3[i][j] = 	matrizJogo[i][j] ;
			}
		}
	}		
		
		
		}
	void mostrarPartidas(){
		if(cont >= 1){
				printf("PRIMEIRA RODADA: \n");
				printf("    0   1   2 \n");
				printf("   ---|---|---\n");
				printf("0  %c  | %c | %c \n", matrizPartida1[0][0], matrizPartida1[0][1],matrizPartida1[0][2]);
				printf("   ---|---|---\n");
				printf("1  %c  | %c | %c \n", matrizPartida1[1][0], matrizPartida1[1][1],matrizPartida1[1][2]);
				printf("   ---|---|---\n");
				printf("2  %c  | %c | %c \n", matrizPartida1[2][0], matrizPartida1[2][1],matrizPartida1[2][2]);
				printf("\n");
		} 
		if(cont >= 2){
			printf("SEGUNDA RODADA: \n");
			printf("    0   1   2 \n");
			printf("   ---|---|---\n");
			printf("0  %c  | %c | %c \n", matrizPartida2[0][0],matrizPartida2[0][1],matrizPartida2[0][2]);
			printf("   ---|---|---\n");
			printf("1  %c  | %c | %c \n", matrizPartida2[1][0], matrizPartida2[1][1],matrizPartida2[1][2]);
			printf("   ---|---|---\n");
			printf("2  %c  | %c | %c \n", matrizPartida2[2][0], matrizPartida2[2][1],matrizPartida2[2][2]);
			printf("\n");
		}
		if(cont >= 3){
			printf("TERCEIRA RODADA: \n");
			printf("    0   1   2 \n");
			printf("   ---|---|---\n");
			printf("0  %c  | %c | %c \n", matrizPartida3[0][0], matrizPartida3[0][1],matrizPartida3[0][2]);
			printf("   ---|---|---\n");
			printf("1  %c  | %c | %c \n", matrizPartida3[1][0], matrizPartida3[1][1],matrizPartida3[1][2]);
			printf("   ---|---|---\n");
			printf("2  %c  | %c | %c \n", matrizPartida3[2][0], matrizPartida3[2][1],matrizPartida3[2][2]);
			printf("\n");
		}
		
		if(pontosJogador1 > pontosJogador2){
			printf("JOGADOR %S VENCEU PARABENS", jogador1);
		}
	}
	



int main(){
	setlocale(LC_ALL, "Portuguese");
	 esvaziandoMatriz();
	/* Menu do jogo*/
		while(inicioJogo != 1){
			menuInicial();
			if(inicioJogo == 2){
				system("cls");
				menuOpcoes();
				inicioJogo = 0;
			}
		}
		
	/* começando */
	nomeJogadores();
	partida();
	for(int i = 0; i < 3; i++){
			turno = 0;
			vitoria = 0;
		for(int j = 0; j < 9; j++){
			turno++;
			partida();
			system("cls");
			
			verificaVitoria();
			if(vitoria == 1){
				j = 10;
			
			}
		}
			salvandoMatriz();
			esvaziandoMatriz();
	}
		mostrarPartidas();
	
		
		
	
	
		
	
	
	return 0;
}