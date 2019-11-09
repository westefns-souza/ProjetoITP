//#include <stdio.h>
#include "primitivas.h"

void preencher_imagem(image* imagem, color* cor);

void gerar_arquivo(FILE* arquivo, image* imagem);

void gerar_linha(image* imagem, line* linha, color* cor);

void gerar_poligono(image* imagem, polygon* poligono, color* cor, line* reta);
