#include <stdio.h>
// int main()
// {
//     int far, cel;
//     int lower, upper, step;

//     lower = 0;
//     upper = 300;
//     step = 20;

//     far = lower;
//     while (far <= upper)
//     {
//       cel = 5 * (far - 32) / 9;
//       printf("%d\t%d\n", far, cel);
//       far += step;
//     }
     
// }
// void main(){
//     float upper, lower, step;
//     float far, cel;

//     lower = 0;
//     upper = 50;
//     step = 5;

//     cel = lower;
//     printf("CELCIUS     FAHRENHEIT\n");
//     while (cel <= upper){
//         far = (cel * 9.0 / 5.0) + 32;
//         printf("%5.1f\t\t%5.1f\n", cel, far);
//         cel += step;
// //     }
// }
void main(){
    int far;
    printf("CELCIUS     FAHRENHEIT\n");
    for(far = 0; far <= 300; far = far + 20)
        printf("%3d\t %6.1f\n", far, (5.0 / 9.0)*(far-32));
}
