#include <stdio.h>

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
    Open
} operacoes;

int main()
{
    FILE* arquivo;
    int i = 0;
    
    arquivo = fopen("arquivo_de_especificacao.txt", "r");
    
    while(!feof(arquivo))
    {
        char linha[100];
        char *result;
        
        result = fgets(linha, 100, arquivo);

        if (result)
        {
            printf("Linha %d : %s\n", i, linha);
        }

        i++;
    }

    fclose(arquivo);

    return 0;
}