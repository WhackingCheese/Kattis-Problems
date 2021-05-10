#include <stdio.h>

int main(int argc, char const *argv[]) {
  int T, n;
  scanf("%d", &T);
  long int N[10005] = {0, 2, 3, 5};
  for(int i = 4; i < 10005; i++) {
    N[i] = (N[i-1] + N[i-2]) % 1000000007;
  }
  for(int i = 0; i < T; i++) {
    scanf("%d", &n);
    printf("%li\n", N[n]);
  }
}
