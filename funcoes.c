#include <stdio.h>
#include "funcoes.h"

void preencher_imagem(image* imagem, color* cor)
{
    for (int linha = 0; linha < imagem->altura; linha++)
    {
        for (int coluna = 0; coluna < imagem->largura; coluna++)
        {   
            imagem->pixels[linha][coluna].r = cor->r;
            imagem->pixels[linha][coluna].g = cor->g;
            imagem->pixels[linha][coluna].b = cor->b;
        }   
    }
}

void gerar_arquivo(FILE* arquivo, image* imagem)
{
    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "%d %d\n", imagem->altura, imagem->largura);
    fprintf(arquivo, "255\n");

    for (int linha = 0; linha < imagem->altura; linha++)
    {
        for (int coluna = 0; coluna < imagem->largura; coluna++)
        {
            color cor = imagem->pixels[linha][coluna];

            fprintf(arquivo, "%d %d %d\n", cor.r, cor.g, cor.b);
        }
    }
}

void gerar_linha(image* imagem, line* linha, color* cor)
{
    int x0 = linha->ponto_inicial->x;
    int x1 = linha->ponto_final->x;

    int y0 = linha->ponto_inicial->y;
    int y1 = linha->ponto_final->y;

    int dx = abs(x1-x0);
    int sx = x0 < x1 ? 1 : -1;

    int dy = abs(y1-y0);
    int sy = y0<y1 ? 1 : -1; 

    int err = (dx>dy ? dx : -dy)/2, e2;
    
    while (1)
    {
        imagem->pixels[x0][y0].r = cor->r;
        imagem->pixels[x0][y0].g = cor->g;
        imagem->pixels[x0][y0].b = cor->b;

        if (x0==x1 && y0==y1)
            break;

        e2 = err;
        if (e2 > -dx)
        { 
            err -= dy;
            x0 += sx; 
        }

        if (e2 < dy) {
            err += dx;
            y0 += sy; 
        }
    }
}

void gerar_poligono(image* imagem, polygon* poligono, color* cor, line* reta)
{
    int k;
    for (int i = 0; i < poligono->quantidade; i++)
    {
        reta->ponto_inicial->x = poligono->pontos[i].x; 
        reta->ponto_inicial->y = poligono->pontos[i].y;

        k = i + 1;
        if (k == poligono->quantidade)
            k = 0;
        
        reta->ponto_final->x = poligono->pontos[k].x; 
        reta->ponto_final->y = poligono->pontos[k].y;

        gerar_linha(imagem, reta, cor);
    }
}

void preencher_figura(image* imagem, fill *preencher, color* cor)
{
    imagem->pixels[preencher->ponto->x][preencher->ponto->y];
}

void gerar_retangulo(image* imagem, rect* retangulo, color* cor, line* reta)
{
    int k;
    for (int i = 0; i < 4; i++)
    {
        reta->ponto_inicial->x = retangulo->ponto->x; 
        reta->ponto_inicial->y = retangulo->ponto->y;

        k = i + 1;
        if (k == 4)
            k = 0;
        
        reta->ponto_final->x = retangulo->largura; 
        reta->ponto_final->y = retangulo->ponto->y;

        gerar_linha(imagem, reta, cor);
    }
}

void gerar_circulo(image* imagem, circle* circulo, color* cor)
{
    midpointCircle(imagem, circulo, cor);
}

void pintar_pixel(image* imagem, int x, int y, color* cor)
{
    imagem->pixels[x][y].r = cor->r;
    imagem->pixels[x][y].g = cor->g;
    imagem->pixels[x][y].b = cor->b;
}

void circlePoints(image* imagem, ponto* coordenada, color* cor)
{
    pintar_pixel(imagem, coordenada->x, coordenada->y, cor);
    pintar_pixel(imagem,  coordenada->x, -coordenada->y, cor);
    pintar_pixel(imagem, -coordenada->x, coordenada->y, cor);
    pintar_pixel(imagem, -coordenada->x, -coordenada->y, cor);
    pintar_pixel(imagem,  coordenada->y, coordenada->x, cor);
    pintar_pixel(imagem,  coordenada->y, -coordenada->x, cor);
    pintar_pixel(imagem, -coordenada->y, coordenada->x, cor);
    pintar_pixel(imagem, -coordenada->y, -coordenada->x, cor);
}

void midpointCircle(image* imagem, circle* circulo, color *cor)
{   

    circulo->ponto->x = 0;
    circulo->ponto->y = circulo->raio;

    int d = 1 - circulo->raio;

    circlePoints(imagem, circulo->ponto, cor);

    while(circulo->ponto->y > circulo->ponto->x) {
        if(d < 0)
            d += 2 * circulo->ponto->x + 3;
        else
        {
            d += 2*( circulo->ponto->x - circulo->ponto->y) + 5;
            circulo->ponto->y--;
        }
        circulo->ponto->x++;
        circlePoints(imagem, circulo->ponto, cor);
    }
}