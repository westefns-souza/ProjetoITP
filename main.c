#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct image_t
{
    int largura;
    int altura;
} image;


typedef struct color_t
{
    int r;
    int g;
    int b;
} color;

typedef struct coordenadas_t
{
    int x;
    int y;
} coordenadas;

typedef struct linha_t
{
    coordenadas cordenada1;

    coordenadas cordenada2;
} linha;

typedef struct polygon_t
{
    int quantidade;
    
    coordenadas *cordenadas;
} polygon;

typedef struct rect_t
{
    coordenadas cordenadas;
    
    int altura;
    int largura;
} rect;

typedef struct circle_t
{
    coordenadas cordenadas;
    
    int raio;
} circle;

typedef struct fill_t
{
    coordenadas cordenadas;
} fill;

enum operacoes 
{
    Save = 1,
    Open,
    Image
} operacoes;

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