#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.c"

int main()
{
    FILE* arquivo_de_especificacao = fopen("arquivo_de_especificacao.txt", "r");

    int operacao;
    image* imagem = malloc(sizeof(image));
    
    color* cor = malloc(sizeof(color));
    cor->r = 255;
    cor->g = 255;
    cor->b = 255;

    line* reta = malloc(sizeof(line));
    reta->ponto_inicial = malloc(sizeof(ponto));
    reta->ponto_final = malloc(sizeof(ponto));

    polygon* poligono = malloc(sizeof(polygon));

    while(!feof(arquivo_de_especificacao))
    {
        char linha[100];
        char *result;

        result = fgets(linha, 100, arquivo_de_especificacao);

        if (result)
        {
            char *token;    

            token = strtok(linha, " ");

            operacao = strcmp(token, "image");

            if (operacao == 0)
            {
                imagem->largura = atoi(strtok(NULL, " "));
                imagem->altura = atoi(strtok(NULL, " "));

                imagem->pixels = malloc(sizeof(color)*imagem->altura);

                for (int i = 0; i < imagem->largura; i++)
                {
                    imagem->pixels[i] = malloc(sizeof(color)*imagem->largura);
                }

                preencher_imagem(imagem, cor);

               continue;
            }

            operacao = strcmp(token, "line");

            if (operacao == 0)
            {

                reta->ponto_inicial->x = atoi(strtok(NULL, " "));
                reta->ponto_inicial->y = atoi(strtok(NULL, " "));

                reta->ponto_final->x = atoi(strtok(NULL, " "));
                reta->ponto_final->y = atoi(strtok(NULL, " "));

                gerar_linha(imagem, reta, cor);

                continue;
            }

            operacao = strcmp(token, "polygon");

            if (operacao == 0)
            {

                poligono->quantidade = atoi(strtok(NULL, " "));

                poligono->pontos = malloc(sizeof(ponto) * poligono->quantidade);

                for (int i = 0; i < poligono->quantidade; i++)
                {
                    poligono->pontos[i].x = atoi(strtok(NULL, " "));
                    poligono->pontos[i].y = atoi(strtok(NULL, " "));
                }

                gerar_poligono(imagem, poligono, cor, reta);
                continue;
            }

            operacao = strcmp(token, "color");

            if (operacao == 0)
            {
                cor->r = atoi(strtok(NULL, " "));
                cor->g = atoi(strtok(NULL, " "));
                cor->b = atoi(strtok(NULL, " "));

                continue;
            }

            operacao = strcmp(token, "save");

            if (operacao == 0)
            {
                char *nome_do_arquivo = strtok(NULL, " ");

                FILE* save = fopen(nome_do_arquivo, "w");
                gerar_arquivo(save, imagem);

                fclose(save);

               continue;
            }

        }
    }

    free(cor);

    for (int i = 0; i < imagem->largura; i++)
        free(imagem->pixels[i]);

    free(imagem->pixels);
    free(imagem);

    free(reta->ponto_final);
    free(reta->ponto_inicial);
    free(reta);

    free(poligono->pontos);
    free(poligono);

    fclose(arquivo_de_especificacao);

    return 0;
}