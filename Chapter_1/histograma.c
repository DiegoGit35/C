#include <stdio.h>

void main(){
    int c;
    int largoPalabras [14], i = 0, j = 0, contador = 0;

    for ( i = 0; i < 14; i++)
    {
        largoPalabras[i] = 0;
    }
    

    while ((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t'){
            largoPalabras[contador] += 1;
            contador = 0;
        }
        else{
            contador++;
        }
    }

    printf("--------HISTOGRAMA--------\n");
    for (i = 0; i < 14; i++)
    {
        printf("largo %3d |", i);
        for ( j = 0; j < largoPalabras[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
}