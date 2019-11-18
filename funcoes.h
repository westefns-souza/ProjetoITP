//#include <stdio.h>
#include "primitivas.h"

void preencher_imagem(image* imagem, color* cor);

void gerar_arquivo(FILE* arquivo, image* imagem);

void gerar_linha(image* imagem, line* linha, color* cor);

void gerar_poligono(image* imagem, polygon* poligono, color* cor, line* reta);

void preencher_figura(image* imagem, fill *fill, color* cor);

void gerar_retangulo(image* imagem, rect* retangulo, color* cor, line* reta);

void pintar_pixel(image* imagem, int x, int y, color* cor);
void gerar_circulo(image* imagem, circle* circulo, color* cor);
void circlePoints(image* imagem, ponto* coordenada, color* cor);
void midpointCircle(image* imagem, circle* circulo, color *cor);