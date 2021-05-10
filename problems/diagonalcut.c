#include <stdio.h>

typedef unsigned long long llu;

llu gcd(llu a, llu b) {
   if(b==0) return a;
   a%=b;
   return gcd(b, a);
}

int main(int argc, char const *argv[]) {
    llu a, b, c;
    scanf("%llu %llu", &a, &b);
    c = gcd(a, b);
    a /= c, b /= c;
    if(a % 2 == 0 || b % 2 == 0) c = 0;
    printf("%llu", c);
    return 0;
}
