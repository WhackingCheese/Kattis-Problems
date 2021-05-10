#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n, h, v, z;
  scanf("%d %d %d", &n, &h, &v);
  z = n/2;
  if (h <= z) h = n-h;
  if (v <= z) v = n-v;
  printf("%lli", v*h*4);
}
