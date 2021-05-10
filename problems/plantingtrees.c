#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int main(int argc, char const *argv[]) {
    int N, d = 2;
    scanf("%d", &N);
    int t[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &t[i]);
    }
    qsort(t, N, sizeof(int), cmp);
    int max = t[0];
    for(int i = 1; i < N; i++) {
        max--, d++;
        if(t[i] > max) {
            max = t[i];
        }
    }
    printf("%d", max+d);
    return 0;
}
