//#include <stdio.h>
#include "primitivas.h"

void preencher_imagem(image* imagem, color* cor);

void gerar_arquivo(FILE* arquivo, image* imagem);

void gerar_linha(image* imagem, line* linha, color* cor);

void gerar_poligono(image* imagem, polygon* poligono, color* cor, line* reta);

void preencher_figura(image* imagem, fill *fill, color* cor);

void gerar_retangulo(image* imagem, rect* retangulo, color* cor, line* reta);

void gerar_circulo(image* imagem, circle* circulo, color* cor, ponto* coordenada);

void drawCircle(image* imagem, circle* circulo, ponto* coordenada, color* cor);

void putpixel(image* imagem, int linha, int coluna, color* cor);