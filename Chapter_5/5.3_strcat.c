#include <stdio.h>
#include <stdlib.h>

// Excercise 5-3. Write a pointer version of the function strcat2 that we showed
// in Chapter 2: strcat2(s, t) copies the string t to the end of s.

void strcat2(char *s,char *t){
    while(*s)
        s++;
    while(*s++ = *t++)
        ;
}

int main()
{
    char s[16] = "we're";
    char *t = " one"; /* read only */
    strcat2(s,t);
    printf("%s\n",s);
    return 0;
}
