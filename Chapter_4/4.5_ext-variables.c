/* Add access to library functions like sin, exp, and pow. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
void printTop(void);
void duplTop(void);
void swapTop(void);
void clearStack(void);

/* reverse Polish calculator */

int main()
{
    int type;
    double op2, op1;
    char s[MAXOP];
    int aux = 0;

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
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
        case 't':
            printTop();
            break;
        case 'd':
            duplTop();
            break;
        case 'w':
            swapTop();
            break;
        case 'c':
            clearStack();
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* ----------------------------------------------------------------------------------------- */

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

/* push: push f onto value stach */
void push(double f)
{
    // printf("%f\n", f);
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

void printTop(void)
{
    for (int i = sp - 1; i > sp - 3; i--)
    {
        printf("%f\n", val[i]);
    }
}

void duplTop(void)
{
    // printf("sp: %d\n", sp);
    val[sp++] = val[sp - 1];
    // printf("sp: %d\n", sp);
}

void swapTop(void)
{
    int aux;

    aux = val[sp - 2];
    val[sp - 2] = val[sp - 1];
    val[sp - 1] = aux;
}

void clearStack()
{
    sp = 0;
}

/* ----------------------------------------------------------------------------------------- */

#include <ctype.h>

int getch(void);

/* getop: get next characteror numeric operand */
int getop(char s[])
{
    int i, c;
    static int lastC = 0;

    if (lastC == 0)
        c = getch();
    else
    {
        c = lastC;
        lastC = 0;
    }

    while ((s[0] = c) == ' ' || c == '\t')
    {
        c = getch();
    }

    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c)){
        printf("%c",s[i]);
        while (isdigit(s[++i] = c = getch()))
        {
            printf("%d",s[i]);
        }
    }
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    s[i] = '\0';

    if (c != EOF)
        lastC = c;

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
