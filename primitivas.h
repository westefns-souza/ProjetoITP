
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

typedef struct ponto_t
{
    int x;
    int y;
} ponto;

typedef struct linha_t
{
    ponto ponto_inicial;

    ponto ponto_final;
} linha;

typedef struct polygon_t
{
    int quantidade;
    
    ponto *pontos;
} polygon;

typedef struct rect_t
{
    ponto ponto;
    
    int altura;
    int largura;
} rect;

typedef struct circle_t
{
    ponto ponto;
    
    int raio;
} circle;

typedef struct fill_t
{
    ponto ponto;
} fill;

enum operacoes 
{
    Save = 1,
    Open,
    Image
} operacoes;