#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include "fogefoge.h"
#include "mapa.h"
#include "ui.h"

char comando = '1';
MAPA m;
POSICAO heroi;

int tempilula = 0;

int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino){
	int opcoes[4][2] = {
		{xatual, yatual+1},
		{xatual+1, yatual},
		{xatual, yatual-1},
		{xatual-1, yatual}
	};

	srand(time(NULL));
	for(int i = 0; i < 10000; i++){
		int posicao = rand() % 4;

		if(podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){

			*xdestino = opcoes[posicao][0];
			*ydestino = opcoes[posicao][1];

			return 1;
		}
		return 0;
	}
}

void fantasmas() {
	MAPA copia;

	copiamapa(&copia, &m);

	for(int i = 0; i < m.linhas; i++){
		for(int j = 0; j < m.colunas; j++){
			if(copia.matriz[i][j] == FANTASMA){
				int xdestino;
				int ydestino;

				int encontrou = praondefantasmavai(i, j, &xdestino, &ydestino);

				if(encontrou){
					andanomapa(&m, i, j, xdestino, ydestino);
				}
				if(podeandar(&m, FANTASMA, i, j+1)){
					andanomapa(&m, i, j, i, j+1);
				}
			}
		}
	}
	liberamapa(&copia);
}

int acabou() {
    POSICAO pos;

    int perdeu = !encontramapa(&m, &pos, HEROI);
    int ganhou = !encontramapa(&m, &pos, FANTASMA);

	if(perdeu || ganhou)
		imprimemapa(&m, comando);

    return ganhou || perdeu;
}

int ehdirecao(char direcao){
	return direcao == ESQUERDA ||
	   direcao == CIMA ||
	   direcao == BAIXO ||
	   direcao == DIREITA;
}

void move(char direcao) {
	
	if(!ehdirecao(direcao))
		return;

	int proximox = heroi.x;
	int proximoy = heroi.y;

	switch(direcao) {
		case ESQUERDA:
			proximoy--;
			break;
		case CIMA:
			proximox--;
			break;
		case BAIXO:
			proximox++;
			break;
		case DIREITA:
			proximoy++;
			break;
	}

	if(!podeandar(&m, HEROI, proximox, proximoy))
		return;
	
	if(ehpersonagem(&m, PILULA, proximox, proximoy))
		tempilula = 1;

	andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
	heroi.x = proximox;
	heroi.y = proximoy;
}

void explodepilula(){
	explodepilula2(heroi.x, heroi.y, 0, 1, 1);
	explodepilula2(heroi.x, heroi.y, 0, -1, 1);
	explodepilula2(heroi.x, heroi.y, 1, 0, 1);
	explodepilula2(heroi.x, heroi.y, -1, 0, 1);
}

void explodepilula2(int x, int y, int somax, int somay, int qtd){
	if(qtd == 0) return;

	int novox = x + somax;
	int novoy = y + somay;

	if(!ehvalida(&m, novox, novoy))
		return;
	if(ehparede(&m, novox, novoy))
		return;
	if(ehpilula(&m, PILULA, novox, novoy))
		return;

	m.matriz[novox][novoy] = VAZIO;
	explodepilula2(novox, novoy, somax, somay, qtd - 1);
}

int main() {
	setlocale(LC_ALL, "Portuguese_Brasil");
	char again = 'S';
	while(again = 'S'){
		system("cls");

		lemapa(&m);
		encontramapa(&m, &heroi, HEROI);
		POSICAO pos;
		do {

			printf("Tem pílula: %s\n", (tempilula ? "SIM" : "NÃO"));
			
			imprimemapa(&m, comando);
		
			scanf(" %c", &comando);
			move(comando);
		
			if(comando == BOMBA && tempilula){
				explodepilula();
				tempilula = 0;
			}


			if(comando != '1'){
				if(encontramapa(&m, &pos, HEROI)){
					fantasmas();
				}
			}

			system("cls");
		} while (!acabou());

		liberamapa(&m);

		int perdeu = !encontramapa(&m, &pos, HEROI);
		int ganhou = !encontramapa(&m, &pos, FANTASMA);

			if(ganhou) {
			printf("\nParabêns, você ganhou!\n\n");

			printf("       ___________      \n");
			printf("      '._==_==_=_.'     \n");
			printf("      .-\\:      /-.    \n");
			printf("     | (|:.     |) |    \n");
			printf("      '-|:.     |-'     \n");
			printf("        \\::.    /      \n");
			printf("         '::. .'        \n");
			printf("           ) (          \n");
			printf("         _.' '._        \n");
			printf("        '-------'       \n\n");

		} else {
			printf("\nQue pena, você morreu pra um fantasma.\n");

			printf("    _______________         \n");
			printf("   /               \\       \n"); 
			printf("  /                 \\      \n");
			printf("//                   \\/\\  \n");
			printf("\\|   XXXX     XXXX   | /   \n");
			printf(" |   XXXX     XXXX   |/     \n");
			printf(" |   XXX       XXX   |      \n");
			printf(" |                   |      \n");
			printf(" \\__      XXX      __/     \n");
			printf("   |\\     XXX     /|       \n");
			printf("   | |           | |        \n");
			printf("   | I I I I I I I |        \n");
			printf("   |  I I I I I I  |        \n");
			printf("   \\_             _/       \n");
			printf("     \\_         _/         \n");
			printf("       \\_______/           \n");
		}
		
		printf("Deseja jogar novamente? (S ou N) ");
		scanf(" %s", &again);
		again = toupper(again);
		if(again == 'N'){
			break;
		}
	}
	system("pause");
}