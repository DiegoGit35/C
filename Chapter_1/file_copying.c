#include <stdio.h>

// void main(){
//     int c;

//     c = getchar();
//     while (c != EOF){
//         putchar(c);
//         c = getchar();
//     }
//     printf("%d\n",EOF);
// }

//  WORD COUNTING
void main(){
    printf("WORD COUNTING\n");

    #define IN  1
    #define OUT 0

    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF){
        ++nc;
        if(c == '\n'){
            ++nl;
        }
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}

