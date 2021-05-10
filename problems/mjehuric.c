#include <stdio.h>

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void print(int a[]) {
    printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
}

int issorted(int a[]) {
    if (a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5) {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    int n[5];
    scanf("%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4]);
    while(!issorted(n)) {
        if(n[0] > n[1]) {
            swap(&n[0], &n[1]);
            print(n);
        }
        if (n[1] > n[2]) {
            swap(&n[1], &n[2]);
            print(n);
        }
        if (n[2] > n[3]) {
            swap(&n[2], &n[3]);
            print(n);
        }
        if (n[3] > n[4]) {
            swap(&n[3], &n[4]);
            print(n);
        }
    }
    return 0;
}
