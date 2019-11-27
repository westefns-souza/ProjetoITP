O que foi feito:
    Foi implementado um programa que lê um arquivo de espeficicação (.txt), contendo comandos, para gerar um arquivo de imagem ppm (.ppm).

Foram implementadas as funções:
    image: 
        especifica a altura e a largura da imagem e preenche com a cor atual;
        ex: image 200 200
    line:
        especifica as coordenadas de dois pontos, o ponto inicial e o ponto final, desenhando uma reta na imagem de um ponto a outro;
        ex: 10 10 50 50
    color:
        define a cor atual, em RGB, a ser usada nos próximos desenhos;
        ex: color 255 0 0
    rect:
        define o ponto de origem do desenho do retangulo, e a altura e largura do mesmo, desenhando na imagem um retangulo;
        ex: rect 10 10 5 20 
    circle:
        define a coordenada central do círculo e o seu raio, gerando uma figura de circulo na imagem;
        ex: circle 25 25 50    
    open:
        Abre e copia todAs as informações em um arquivo ppm e armazena o tamanho da imagem e os pixels na struct de imagem;
        ex: open teste.ppm 
    save:
        Gerar um novo arquivo ppm com o nome espeficicado contendo usando as informações da struct de imagem.
        ex: save teste.ppm
    polygon:
        Define uma certa quantidade de pontos e suas respectivas coordenadas, em seguida gera um polígono com os pontos informados.
        ex: polygon 3 0 0 0 99 50 99
    clear:
        Recebe uma nova cor e preenche toda a imagem com ela, sobreescrevendo toda a imagem.
        ex: clear 0 0 0
    fill:
        Recebe um ponto, e preenche apartir desse ponto todo o espaço dentro ou fora de uma figura, com a cor atual 
        ex: fill 20 20

O que não foi feito:
    A funcionalidade fill, foi implementado, mas contendo bugs, pintando mais que o necessário.

O que seria feito diferentemente:
    Criar as imagens, já escrevendo no arquivo (.ppm), dificultando o prosseguimento do projeto, tendo que ser refeito utilizando as estruturas.
    Criando inicialmente  os arquivos (.c) e (.h), fazendo a modularização, para que o arquivo main ficasse mais enxuto.
    Utilizar a alocação dinâmicamente logo de início.
    Fazer a documentação desde de início.

Ponto Extra:
    Uso do GitHub:
        Link do GitHub: https://github.com/westefns-souza/ProjetoITP

Como compilar:
    gcc main.c -o main
    
executar
    ./main

Autores:
    Anderson Bezerra Da Rocha
    Westefns Damião de Souza Silva