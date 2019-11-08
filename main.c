#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.c"

int main()
{
    FILE* arquivo_de_especificacao;
    FILE* arquivo_auxiliar;

    int operacao;
    image* imagem;
    color* cor_1;
    color* cor_2;
    line* reta;

    arquivo_de_especificacao = fopen("arquivo_de_especificacao.txt", "r");;
    arquivo_auxiliar = fopen("arquivo_auxiliar.ppm", "w+");

    imagem = malloc(sizeof(image));
    cor_1 = malloc(sizeof(color));
    cor_2 = malloc(sizeof(color));
    
    reta = malloc(sizeof(line));
    reta->ponto_inicial = malloc(sizeof(ponto));
    reta->ponto_final = malloc(sizeof(ponto));

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

                cor_1->r = 0;
                cor_1->g = 0;
                cor_1->b = 0;

                preencher_imagem(imagem, cor_1);

               continue;
            }

            operacao = strcmp(token, "line");

            if (operacao == 0)
            {
                reta->ponto_inicial->x = atoi(strtok(NULL, " "));
                reta->ponto_inicial->y = atoi(strtok(NULL, " "));

                reta->ponto_final->x = atoi(strtok(NULL, " "));
                reta->ponto_final->y = atoi(strtok(NULL, " "));

                cor_2->r = 0;
                cor_2->g = 200;
                cor_2->b = 0;

                gerar_linha(imagem, reta, cor_2);
                continue;
            }

            operacao = strcmp(token, "save");

            if (operacao == 0)
            {

                char *nome_do_arquivo = strtok(NULL, " ");
                gerar_arquivo(arquivo_auxiliar, imagem);

                FILE* save = fopen(nome_do_arquivo, "w+");

                fclose(arquivo_auxiliar);

                arquivo_auxiliar = fopen("arquivo_auxiliar.ppm", "r");

                char linha_ppm[100];
                char *result_ppm;

                while(!feof(arquivo_auxiliar))
                {

                    result_ppm = fgets(linha_ppm, 100, arquivo_auxiliar);

                    if (result_ppm)
                    {
                        fprintf(save, "%s", linha_ppm);
                    }
                }

                fclose(arquivo_auxiliar);
                arquivo_auxiliar = fopen("arquivo_auxiliar.ppm", "a");

                fclose(save);

               continue;
            }
        }
    }

    free(cor_1);
    free(cor_2);

    for (int i = 0; i < imagem->largura; i++)
        free(imagem->pixels[i]);

    free(imagem->pixels);
    free(imagem);
    free(reta->ponto_inicial);
    free(reta->ponto_final);
    free(reta);

    fclose(arquivo_auxiliar);
    fclose(arquivo_de_especificacao);

    return 0;
}