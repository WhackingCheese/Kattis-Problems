#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main(int argc, char const *argv[]){
    int n, a = 0;
    scanf("%d", &n);
    int H[n];
    for( int i = 0; i < n; i++ ) {
        scanf("%d", &H[i]);
    }
    qsort(H, n, sizeof(int), cmp);
    for(int i = 0; i < n; i++) {
        if(H[i] >= i+1){
            a = i+1;
        } else {
            break;
        }
    }
    printf("%d", a);
    return 0;
}
