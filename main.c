#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.c"

int main()
{
    FILE* arquivo_de_especificacao = fopen("arquivo_de_especificacao.txt", "r");;
    FILE* arquivo_auxiliar = fopen("arquivo_auxiliar.ppm", "w+");;

    int operacao;
    image* imagem;
    color* cor;

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
                
                color pixels[imagem->largura][imagem->altura];
                imagem->pixels = (color**) pixels;
                
                cor->r = 0;
                cor->g = 255;
                cor->b = 0;
                
                preencher_imagem(imagem, cor);

                gerar_arquivo(arquivo_auxiliar, imagem);
                            
               continue;
            }

            operacao = strcmp(token, "save");

            if (operacao == 0)
            {

                char *nome_do_arquivo = strtok(NULL, " ");

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

    fclose(arquivo_auxiliar);
    fclose(arquivo_de_especificacao);

    return 0;
}