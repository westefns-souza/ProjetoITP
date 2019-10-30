#include <stdio.h>
#include <string.h>
#include "primitivas.h"

int main()
{
    FILE* arquivo;
    FILE* arquivo_ppm;
    FILE *save;
    FILE *aux;

    int operacao;

    arquivo = fopen("arquivo_de_especificacao.txt", "r");
    arquivo_ppm = fopen("arquivo_auxiliar.ppm", "w+");

    fprintf(arquivo_ppm, "P3\n");

    while(!feof(arquivo))
    {
        char linha[100];
        char *result;
        
        result = fgets(linha, 100, arquivo);

        if (result)
        {
            char *token;

            token = strtok(linha, " ");

            operacao = strcmp(token, "image");

            if (operacao == 0)
            {
                image imagem;

                imagem.largura = atoi(strtok(NULL, " "));
                imagem.altura = atoi(strtok(NULL, " "));

               fprintf(arquivo_ppm, "%d %d\n", imagem.largura, imagem.altura);

               continue;
            }

            operacao = strcmp(token, "save");

            if (operacao == 0)
            {
                char *nome_do_arquivo = strtok(NULL, " ");

                save = fopen(nome_do_arquivo, "w+");

                fclose(arquivo_ppm);

                aux = fopen("arquivo_auxiliar.ppm", "r");
                
                char linha_ppm[100];
                char *result_ppm;
                while(!feof(aux))
                {
        
                    result_ppm = fgets(linha_ppm, 100, aux);
                    
                    if (result_ppm)
                    {
                        fprintf(save, "%s", linha_ppm);
                    }
                }

                fclose(aux);

               continue;
            }
        }
    }
    
    fclose(save);
    fclose(arquivo);

    return 0;
}