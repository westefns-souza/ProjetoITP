#include <stdio.h>
#include "funcoes.h"

void preencher_imagem(image* imagem, color* cor)
{
    for (int linha = 0; linha < imagem->largura; linha++)
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
    fprintf(arquivo, "%d %d\n", imagem->largura, imagem->altura);
    fprintf(arquivo, "255\n");

    for (int linha = 0; linha < imagem->largura; linha++)
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
    int x1 = linha->ponto_final->x;
    int x0 = linha->ponto_inicial->x;

    int y1 = linha->ponto_final->y;
    int y0 = linha->ponto_inicial->y;

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