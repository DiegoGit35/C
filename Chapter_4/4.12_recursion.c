#include <stdio.h>
#include <string.h>
/* printd: print n in decimal */
// void printd(int n)
// {
//     if (n < 0)
//     {
//         putchar('-');
//         n = -n;
//     }
//     if (n / 10)
//         printd(n / 10);
//     putchar(n % 10 + '0');
// }

/* reverse: reverse string s in place */
// void reverse(char s[])
// {
//     int c, i, j;
//     for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
//     {
//         c = s[i];
//         s[i] = s[j];
//         s[j] = c;
//     }
// }

// /* itoa: convert n to characters in s */
// void itoa(int n, char s[])
// {
//     int i, sign;

//     if ((sign = n) < 0)
//         n = -n;
//     i = 0;
//     do
//     {
//         s[i++] = n % 10 + '0'; /* 0 es 48 en ASCII*/
//     } while ((n /= 10) > 0); /* eliminamos el ultimo digito */
//     if (sign < 0)
//         s[i++] = '-';
//     s[i] = '\0';
//     reverse(s);

// }

int i = 0;

void myItoa(int n, char s[])
{
    int sign;
    if (n / 10)
    {
        myItoa(n / 10, s);
        printf("%d\n", n / 10);
    }
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}

int main()
{
    char str[10];
    myItoa(113125, str);
    printf("%s\n", str);

    return 0;
}
