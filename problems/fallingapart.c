#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int main(int argc, char const *argv[]) {
    int N, a = 0, b = 0;
    scanf("%d", &N);
    int t[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &t[i]);
    }
    qsort(t, N, sizeof(int), cmp);
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            a += t[i];
        } else {
            b += t[i];
        }
    }
    printf("%d %d", a, b);
    return 0;
}
