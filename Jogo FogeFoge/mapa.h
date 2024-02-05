#ifndef _MAPA_H_
#define _MAPA_H_

#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'
#define PILULA 'P'
#define EXPLOSAO '*'

struct mapa {
	char** matriz;
	int linhas;
	int colunas; 
};

typedef struct mapa MAPA;

struct posicao {
	int x;
	int y;
};

typedef struct posicao POSICAO;
int ehpilula(MAPA* m, char pilula, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);
int ehparede(MAPA* m, int x, int y);
int podeandar(MAPA* m, char personagem, int x, int y);
void copiamapa(MAPA* destino, MAPA* origem);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
int encontramapa(MAPA* m, POSICAO* p, char c);
void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void liberamapa(MAPA* m);

#endif