#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define rep(E, F) for (E = 0; E < (F); E++)
#define EPS 1e-9

typedef double complex dc;

int bxb(double a, double b, double c, double d) {
    if (a > b) return bxb(b, a, c, d);
    if (c > d) return bxb(a, b, d, c);
    return fmax(a, c) <= fmin(b, d);
}

int ccw(dc a, dc b, dc c) {
    double f = cimag((c - a)/(b - a));
    if (fabs(f) < EPS) return 0;
    if (f < EPS) return -1;
    return 1;
}

int lxl(dc a, dc b, dc c, dc d) {
    int a1 = ccw(a, b, c), a2 = ccw(a, b, d), a3 = ccw(c, d, a), a4 = ccw(c, d, b);
    if (a1*a2*a3*a4 == 0) return 0;
    if (a1*a2 != -1 || a3*a4 != -1) return 0;
    return bxb(creal(a), creal(b), creal(c), creal(d))&& bxb(cimag(a), cimag(b), cimag(c), cimag(d));
}

double p2l(dc p, dc l1, dc l2){
    p = (p - l1)*cexp(-I*carg(l2 - l1));
    if (-EPS < creal(p) && creal(p) < cabs(l2 - l1) + EPS) return fabs(cimag(p));
    return fmin(cabs(p), cabs(p - cabs(l2 - l1)));
}
double l2l(dc a1, dc a2, dc b1, dc b2) {
    if (cabs(a1 - a2) < EPS && cabs(b1 - b2) < EPS) return cabs(a1 - b1);
    if (cabs(a1 - a2) < EPS) return p2l(a1, b1, b2);
    if (cabs(b1 - b2) < EPS) return p2l(b1, a1, a2);
    if (lxl(a1, a2, b1, b2)) return 0.0;
    return fmin(fmin(p2l(a1, b1, b2), p2l(a2, b1, b2)), fmin(p2l(b1, a1, a2), p2l(b2, a1, a2)));
}

int main() {
    int n, x, y;
    double res;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        dc p[4];
        for (int j = 0; j < 4; j++) {
            scanf("%d %d", &x, &y);
            p[j] = x + I*y;
        }
        res = l2l(p[0], p[1], p[2], p[3]);
        if (res == 0.0) res = 0.0;
        printf("%.2f\n", res);
    }
    return 0;
}
