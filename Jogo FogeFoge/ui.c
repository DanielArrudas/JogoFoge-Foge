#include <stdlib.h>
#include <stdio.h>
#include "fogefoge.h"
#include "ui.h"
#include "mapa.h"

char desenhofantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};
char desenhoparede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};
char desenhoheroi_direita[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};
char desenhoheroi_esquerda[4][7] = {
    {" .--. "  },
    {"'-._ \\" },
    {".-'  /" },
    {" '--' "  }
};

char desenhoheroi_cima[4][7] = {
    {".'\\/'." },
    {"|    |"  },
    {"\\    /" },
    {" ---- "  }
};

char desenhoheroi_baixo[4][7] = {
    {" ____ " },
    {"/    \\" },
    {"|    |"  },
    {" ./\\. " },
};

char desenhopilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void imprimeparte(char desenho[4][7], int parte){
    printf("%s", desenho[parte]);
}
void desenhoheroi(char comando, int parte){
    if(comando == DIREITA){
        imprimeparte(desenhoheroi_direita, parte);
    }
    else if(comando == ESQUERDA){
        imprimeparte(desenhoheroi_esquerda, parte);
    }
    else if(comando == CIMA)
        imprimeparte(desenhoheroi_cima, parte);
    else if(comando == BAIXO)
        imprimeparte(desenhoheroi_baixo, parte);
    else{
        imprimeparte(desenhoheroi_esquerda, parte);
    }
}
void imprimemapa(MAPA* m, char comando) {
	for(int i = 0; i < m->linhas; i++) {

        for(int parte = 0; parte < 4; parte++){

            for(int j = 0; j < m->colunas; j++){

                switch(m->matriz[i][j]){
                    case FANTASMA:
                        imprimeparte(desenhofantasma, parte);
                            break;
                    case HEROI:
                        desenhoheroi(comando, parte);
                        break;
                    case PILULA:
                        imprimeparte(desenhopilula, parte);
                        break;
                    case PAREDE_HORIZONTAL:
                    case PAREDE_VERTICAL:
                        imprimeparte(desenhoparede, parte);
                        break;
                    case VAZIO:
                        imprimeparte(desenhovazio, parte);
                }
            }
            printf("\n");
        }
	}
}