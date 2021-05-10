#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int A[n], B[n];
    for ( int i = 0; i < n; i++ ) {
        scanf( "%d", &A[i] );
    }
    for ( int i = 0; i < n; i++ ) {
        scanf( "%d", &B[i] );
    }
    long a[3] = {0}, b[3] = {0};
    for ( int i = 0; i < n; i++ ) {
        switch ( i % 3 ) {
            case 0:
                a[0] += A[i];
                b[0] += B[i];
                break;
            case 1:
                a[1] += A[i];
                b[1] += B[i];
                break;
            case 2:
                a[2] += A[i];
                b[2] += B[i];
                break;
        }
    }
    printf(
        "%ld %ld %ld",
        a[0]*b[1] + a[1]*b[0] + a[2]*b[2],
        a[0]*b[2] + a[1]*b[1] + a[2]*b[0],
        a[0]*b[0] + a[1]*b[2] + a[2]*b[1]
    );
    return 0;
}
