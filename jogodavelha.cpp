

#include <iostream>
#include <stdio.h>
#include<string.h>
#include<string>
#include<conio.h>
#include <locale.h>
#include<windows.h>
#include<fstream>


using namespace std;



/* variaveis*/ 

int cont = 0, movimentaCursor, inicioJogo = 0, turno = 0, posicaoLinha= 0, posicaoColuna= 0, pontosJogador1 = 0, pontosJogador2 = 0 , vitoria = 0, reseta = 0;
char aux, data[11], indiceMenu[3] = {' ', '@', ' '}, matrizJogo[3][3], jogador1[20], jogador2[20], matrizPartida1[3][3], matrizPartida2[3][3], matrizPartida3[3][3], matrizVerificadora[3][3];
string linha;

	/*fun?oes*/
	void salvandoHistorico(){
		ofstream meuArquivo("historico.txt", ios::app);
			if(meuArquivo.is_open()){	
				meuArquivo << jogador1 << ": "<<pontosJogador1 << " X " << jogador2 << ": " << pontosJogador2 << endl << data;
			}else{
				cout<<"nao foi possivel abrir o arquivo";
			}
		meuArquivo.close();
}
	void mostrandoHistorico(){
	fstream meuArquivo("historico.txt");
	if(meuArquivo.is_open()){
		cout<<"*** Listagem do arquivo ***"<< endl;
		while(getline(meuArquivo,linha)){
		cout<< linha << endl;
		}
	}else{
		cout<< "erro na abertura do arquivo"<< endl;
	}
}
	void upMenu(){
		aux = indiceMenu[0];
		indiceMenu[0] = indiceMenu[1];
		indiceMenu[1] = indiceMenu[2];
		indiceMenu[2] = aux;
		
	}
	void downMenu(){
		aux = indiceMenu[0];
		indiceMenu[0] = indiceMenu[2];
		indiceMenu[2] = indiceMenu[1];
		indiceMenu[1] = aux;
		
	}
	void menuInicial(){
		printf("*** #JOGO DA VELHA# ***\n");
		printf("         JOGAR         \n");
		printf("       instru?oes      \n");
		printf("       hist?rico       \n");
		while(inicioJogo != 1 && inicioJogo != 2){
				
		if(!kbhit()){
			 movimentaCursor = getch();
			 system("cls");
			 switch(movimentaCursor){
			 	case 119:
			 		system("cls");
			 		upMenu();
			 	printf("*** #JOGO DA VELHA# ***\n");
			 	printf("      %c JOGAR         \n",indiceMenu[0]);
			 	printf("    %c instru?oes      \n",indiceMenu[1]);
			 	printf("    %c hist?rico       \n",indiceMenu[2]);
			 	break;
			 	
			 	case 115:
			 		system("cls");
			 		downMenu();
	 			printf("*** #JOGO DA VELHA# ***\n");
			 	printf("      %c JOGAR         \n",indiceMenu[0]);
			 	printf("    %c instru?oes      \n",indiceMenu[1]);
			 	printf("    %c hist?rico       \n",indiceMenu[2]);
			 		
				break;
				
				case 101:
					if(indiceMenu[0] == '@'){
						inicioJogo = 1;
					}else if(indiceMenu[1] == '@'){
						inicioJogo = 2;
					}else if(indiceMenu[2] == '@'){
						inicioJogo = 3;
					}
				break;
			 	}
				
			}
			
		}
		
	}
	void menuOpcoes(){
		
		
			printf("Ola, esse ? um jogo da velha feito por Gabriel Lopo para um projeto da faculdade.\n");
			printf("* Para jogar ? muito simples, selecione a linha e a coluna desejada *\n");
			printf("* E o sistema automaticamente marcara sua op?ao :) *\n");
			printf("* lembre que o jogo ? uma melhor de 3 entao nao desanime se perder uma rodada *\n");
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
			printf("valor de posi?ao invalido\n");
			printf("escolha a linha desejada: ");
			scanf("%d", &posicaoLinha);
		}
		
			printf("escolha a colua desejada: ");
			scanf("%d", &posicaoColuna);
			while(!(posicaoColuna <= 2) || !(posicaoColuna >= 0)){
				printf("valor de posi?ao invalido\n");
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
		(matrizJogo[0][1] == 'X' && matrizJogo[1][1] == 'X' && matrizJogo[2][1] == 'X') ||
		(matrizJogo[0][2] == 'X' && matrizJogo[1][2] == 'X' && matrizJogo[2][2] == 'X')||
		(matrizJogo[0][2] == 'X' && matrizJogo[1][1] == 'X' && matrizJogo[2][0] == 'X')){
			 vitoria = 1;
			 pontosJogador1++;
			 
			 printf("JOGADOR %s(X) venceu essa rodada\n", jogador1);
			 printf("carregando proxima rodada...\n");
			 Sleep(5000);
			 system("cls");
			 
		}else if((matrizJogo[0][0] == 'O' && matrizJogo[1][1] == 'O' && matrizJogo[2][2] == 'O') || 
		(matrizJogo[0][0] == 'O' && matrizJogo[0][1] == 'O' && matrizJogo[0][2] == 'O') || 
		(matrizJogo[1][0] == 'O' && matrizJogo[1][1] == 'O' && matrizJogo[1][2] == 'O') || 
		(matrizJogo[2][0] == 'O' && matrizJogo[2][1] == 'O' && matrizJogo[2][2] == 'O') ||
		(matrizJogo[0][0] == 'O' && matrizJogo[1][0] == 'O' && matrizJogo[2][0] == 'O') ||
		(matrizJogo[0][1] == 'O' && matrizJogo[1][1] == 'O' && matrizJogo[2][1] == 'O') ||
		(matrizJogo[0][2] == 'O' && matrizJogo[1][2] == 'O' && matrizJogo[2][2] == 'O')||
		(matrizJogo[0][2] == 'O' && matrizJogo[1][1] == 'O' && matrizJogo[2][0] == 'O')){
			vitoria = 2;
			pontosJogador2++;
			
			printf("JOGADOR %s(0) venceu essa rodada\n", jogador2);
			printf("carregando proxima rodada...\n");
			Sleep(5000);
			system("cls");
			
			
			
		}else if( matrizJogo[0][0] != ' ' && matrizJogo[0][1] != ' ' && matrizJogo[0][2] != ' ' &&
		 matrizJogo[1][0] != ' ' && matrizJogo[1][1] != ' ' && matrizJogo[1][2] != ' ' &&
		  matrizJogo[2][0] != ' ' && matrizJogo[2][1] != ' '&& matrizJogo[2][2] != ' '){
			printf("Rodada empatada...");
			vitoria = 3;
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
		}else if(pontosJogador1 < pontosJogador2){
			printf("JOGADOR %S VENCEU PARABENS", jogador2);
		}else{
			printf("houve um empate... UOU!!!!!");
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
			if(inicioJogo == 3){
				system("cls");
				mostrandoHistorico();
				inicioJogo = 0;
			}
		}
		
	/* come?ando */
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
			if(vitoria == 1 || vitoria == 2 || vitoria ==3 ){
				j = 10;
			
			}
		}
			salvandoMatriz();
			esvaziandoMatriz();
	}
		mostrarPartidas();
		salvandoHistorico();
		
		
	
	
		
	
	
	return 0;
}
