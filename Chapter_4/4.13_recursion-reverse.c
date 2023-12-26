#include <stdio.h>
#include <string.h>

/* exercise 4-13: write a recursive version of the function reverse(s), which
reverses the string s in place */
int i = 1;
char aux;
void reverse(char s[])
{
    if(i <= strlen(s)/2)
    {
        aux = s[strlen(s) - i];
        s[strlen(s)-i] = s[i-1];
        s[i-1] = aux;
        i++;
        reverse(s);
    }
}

int main(int argc, char const *argv[])
{
    char str[] = "diego";
    reverse(str);
    printf("%s\n", str);
    return 0;
}