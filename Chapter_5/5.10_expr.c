#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Write the program expr, which  evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example:
    ./expr 2 3 4 + *
evaluates e * (3 + 4) */

#define NUMBER '0'
#define MAXOP   100

int getop(char []);
void push(double);
double pop(void);

int main(int argc, char const *argv[])
{
    double op1, op2;
    char s[MAXOP];
    printf("argc vale: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("**argv vale: %c\n", **argv);
        s[i] = **++argv;        
    }
    
    while (--argc > 0)
    {
        // printf("argv vale: %c\n", *argv);
        
        switch (getop(s))
        {
        case NUMBER:
            printf("argv vale: %s\n", *argv);
            push(atof(*argv));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            // printf("%f\n",op2);
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            break;
        default:
            printf("error: unknown command %s\n", *argv);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
        // printf("%f\n", val[sp-1]);
    }
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);


/* getop: get next characteror numeric operand */
int getop(char s[]){
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
        
    s[1] = '\0'; /* lo asigna por las dudas, no sabe si lo proximo que lea 
                    va a ser un digito */
    i = 0;
    if (c == '-')
        if(!isdigit(s[++i] = c = getch())){
            ungetch(c);
            c = s[0];
        }
        
    if (!isdigit(c) && c != '.')
        return c;
    if(isdigit(c)){
        /* aunque impresionante es muy dificil de leer >.< */
        while (isdigit(s[++i] = c = getch()))/* leer numero de mas de una cifra
                                                no sabe que hacer si aparece un . */
            ;
    }
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void)
{
    // printf("%d\n", bufp);
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        // printf("%d c es un: %d\n", bufp, c);
        buf[bufp++] = c;
    }
}
