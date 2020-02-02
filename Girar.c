#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct imagem img;

struct imagem{
    int a,b,c;
};
FILE *arquivo;
FILE *girar;
img **K;

int main(){
    setlocale(LC_ALL,"Portuguese");
    arquivo = fopen("pinguim.ppm","r");

    int g, h, i, j, Cor;
    char string[6];

    fscanf(arquivo,"%s",string);
    fscanf(arquivo,"%d",&g);
    fscanf(arquivo,"%d",&h);
    fscanf(arquivo,"%d",&Cor);
    if (g >= h){
        K = malloc(g * sizeof(img));
        for (i=0;i<g;i++)
            K[i] = malloc(g * sizeof(img));
    } else {
        K = malloc(h * sizeof(img));
        for (i=0;i<g;i++)
            K[i] = malloc(h * sizeof(img));
    }

    for (i=0;i<g;i++){
        for(j=0;j<h;j++){
            fscanf(arquivo,"%d",&K[i][j].a);
            fscanf(arquivo,"%d",&K[i][j].b);
            fscanf(arquivo,"%d",&K[i][j].c);
        }
    }

    fclose(arquivo);

    girar = fopen("pinguim180.ppm","w");
    fprintf(arquivo,"%s\n",string);
    fprintf(arquivo,"%d\n",g);
    fprintf(arquivo,"%d\n",h);
    fprintf(arquivo,"%d\n",Cor);
    for(i=0;i<g;i++){
        for(j=0;j<h;j++){
            fprintf(arquivo,"%d\n",K[255-i][j].a);
            fprintf(arquivo,"%d\n",K[255-i][j].b);
            fprintf(arquivo,"%d\n",K[255-i][j].c);
        }
    }
    fclose(girar);
    return 0;

}
