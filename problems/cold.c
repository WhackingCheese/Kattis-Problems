#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n, t, c=0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        if(t < 0) {c++;}
    }
    printf("%d", c);
    return 0;
}
