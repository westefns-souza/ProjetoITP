#include <stdio.h>
#include <math.h>
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

void gerar_retangulo(image* imagem, rect* retangulo, color* cor, line* reta)
{
    int k;
    for (int i = 0; i < 4; i++)
    {

        //int x, y, xo, yo;

        reta->ponto_inicial->x = retangulo->ponto->x;
        reta->ponto_inicial->y = retangulo->ponto->y;

        reta->ponto_final->x = reta->ponto_inicial->x;
        reta->ponto_final->y = reta->ponto_inicial->y + retangulo->altura;

        gerar_linha(imagem, reta, cor);

        reta->ponto_inicial->x = reta->ponto_final->x;
        reta->ponto_inicial->y = reta->ponto_final->y;

        reta->ponto_final->x = reta->ponto_inicial->x + retangulo->largura;
        reta->ponto_final->y = reta->ponto_inicial->y;

        gerar_linha(imagem, reta, cor);

        reta->ponto_inicial->x = reta->ponto_final->x;
        reta->ponto_inicial->y = reta->ponto_final->y;

        reta->ponto_final->x = reta->ponto_inicial->x;
        reta->ponto_final->y = reta->ponto_inicial->y - retangulo->altura;

        gerar_linha(imagem, reta, cor);

        reta->ponto_inicial->x = reta->ponto_final->x;
        reta->ponto_inicial->y = reta->ponto_final->y;

        reta->ponto_final->x = reta->ponto_inicial->x - retangulo->largura;
        reta->ponto_final->y = reta->ponto_inicial->y;

        gerar_linha(imagem, reta, cor);

    }
}

void gerar_circulo(image* imagem, circle* circulo, color* cor, ponto* coordenada)
{
    coordenada->x = 0;
    coordenada->y = circulo->raio;
    int d = 3 - 2 * circulo->raio; 

    drawCircle(imagem, circulo, coordenada, cor);

    while (coordenada->y >= coordenada->x) 
    {     
        coordenada->x++;
  
        if (d > 0) 
        { 
            coordenada->y--;  
            d = d + 4 * (coordenada->x - coordenada->y) + 10; 
        } 
        else
        {
            d = d + 4 * coordenada->x + 6; 
        }

        drawCircle(imagem, circulo, coordenada, cor);
    } 

}

void drawCircle(image* imagem, circle* circulo, ponto* coordenada, color* cor) 
{ 
    // https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
    putpixel(imagem, circulo->ponto->x + coordenada->x, circulo->ponto->y + coordenada->y, cor); 
    putpixel(imagem, circulo->ponto->x - coordenada->x, circulo->ponto->y + coordenada->y, cor); 
    putpixel(imagem, circulo->ponto->x + coordenada->x, circulo->ponto->y - coordenada->y, cor); 
    putpixel(imagem, circulo->ponto->x - coordenada->x, circulo->ponto->y - coordenada->y, cor); 
    putpixel(imagem, circulo->ponto->x + coordenada->y, circulo->ponto->y + coordenada->x, cor); 
    putpixel(imagem, circulo->ponto->x - coordenada->y, circulo->ponto->y + coordenada->x, cor); 
    putpixel(imagem, circulo->ponto->x + coordenada->y, circulo->ponto->y - coordenada->x, cor); 
    putpixel(imagem, circulo->ponto->x - coordenada->y, circulo->ponto->y - coordenada->x, cor); 
}

void putpixel(image* imagem, int linha, int coluna, color* cor)
{
    imagem->pixels[linha][coluna].r = cor->r;
    imagem->pixels[linha][coluna].g = cor->g;
    imagem->pixels[linha][coluna].b = cor->b;
}