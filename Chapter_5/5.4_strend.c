#include <stdio.h>
#include <string.h>

// Excercise 5-4. Write the function strend(s,t), which returns 1 if the
// string t occurs at the end of the string s, and zero otherwise.

int strend(char *s, char *t)
{
    int lent = strlen(t);
    int lens = strlen(s);
    int equals = 1;

    for (int i = lens - lent; i < lens; i++)
    {
        // printf("%c   %c\n", s[i], *t);
        if (s[i] != *t++)
        {
            equals = 0;
            break;
        }
    }
    return equals;
}

int main(int argc, char const *argv[])
{
    char *t = "diego";
    char *s = "mi nombre es diego";

    printf("%d\n", strend(s, t));
    return 0;
}
