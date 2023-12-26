#include <stdio.h>
#define swap(t, x, y) {t _z; \
                        _z = x; \
                        x = y; \
                        y = _z;}

/* Excercise 4-14: define a macro swap(t, x, y) that interchanges two arguments
 of type t */
 
 int main(int argc, char const *argv[])
 {
    int x = 4;
    int y = 6;

    swap(int, x, y);
    printf("%d %d\n", x, y);
    return 0;
 }
 