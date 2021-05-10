#include <stdio.h>

int main(int argc, char const *argv[]) {
    int c, i, t = 0;
    char s[100];
    scanf("%s", s);
    while (s[i] != '\0') {
        if (s[i] == '-') {
            c++;
        }
        i++;
    }
    char r[c+1];
    r[0] = s[0];
    i = 0;
    while(s[i] != '\0') {
        if (t == c) {
            break;
        }
        if (s[i] == '-') {
            r[t+1] = s[i+1];
            t++;
        }
        i++;
    }
    printf("%s", r);
    return 0;
}
