#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x, y, n;

    scanf("%d %d %d", &x, &y, &n);
    
    for(int i = 1; i <= n; i++) {
        if(i % x != 0 && i % y != 0) {
            printf("%d", i);
        }
        else {
            if(i % x == 0) {
                printf("Fizz");
            }
            if(i % y == 0) {
                printf("Buzz");
            }
        }
        printf("\n");
    }
    return 0;
}
