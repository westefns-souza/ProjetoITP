#include <stdio.h>
#include "funcoes.h"

void preencher_imagem(image* imagem, color* cor)
{
//    color** pixels;

    if (cor == NULL)
    {
        cor->r = 255;
        cor->g = 255;
        cor->b = 255;
    }

    for (int linha = 0; linha < imagem->largura; linha++)
    {
        for (int coluna = 0; coluna < imagem->largura; coluna++)
        {   
            imagem->pixels[linha][coluna].r = cor->r;
            imagem->pixels[linha][coluna].g = cor->g;
            imagem->pixels[linha][coluna].b = cor->b;
        }   
    }

  //  imagem->pixels = pixels;
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