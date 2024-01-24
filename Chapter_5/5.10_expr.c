/* Write the program expr, which  evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example:
    ./expr 2 3 4 + *
evaluates e * (3 + 4) */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER '0'

double pop(void);
void push(double);
int getop(const char *);

int main(int argc, char const *argv[])
{
    int op1, op2;
    char **numeros;
    while (--argc > 0)
    {
        //
        switch (getop(*++argv))
        {
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '+':
            push(pop() + pop());
            break;
        case 'x': /* por alguna razon * introduce el contenido de la carpeta 
        actual como argumentos, Bash fault??*/
            push(pop() * pop());
            break;
        case NUMBER:
            push(atof(*argv));
            break;
        default:
            break;
        }
    }
    printf("\t%.8g\n", pop());

    return 0;
}

int getop(const char *s)
{
    if (isdigit(s[0]))
    {   
        return NUMBER;
    }
    else
    {
        return s[0];
    }
}

#define MAXVAL 100
double val[MAXVAL];
int sp = 0;

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
        printf("error\n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        return 0.0;
    }
}
