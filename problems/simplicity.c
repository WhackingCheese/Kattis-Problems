#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    char alph[27] = "";
    int ralph[27];
    char txt[101];
    scanf("%s", &txt);
    int i = 0, n = 0;
    while(txt[i] != '\0'){
        if(!strchr(alph, txt[i])) {
            alph[n] = txt[i];
            n++;
        }
        i++;
    }
    if (n == 1 || n == 2) {
        printf("0");
        return 0;
    }
    for(int i = 0; i < n; i++) {
        ralph[i] = 0;
        for(int j = 0; j < strlen(txt); j++) {
            if(txt[j] == alph[i]) {
                ralph[i]++;
            }
        }
    }
    int max1 = 0, max2 = 0;
    for (int i = 0; i < n; i++) {
        if (ralph[i] > max1) {
            max2 = max1;
            max1 = ralph[i];
        } else if (ralph[i] == max1) {
            max2 = max1;
        } else if (ralph[i] > max2) {
            max2 = ralph[i];
        }
    }
    printf("%d", strlen(txt)-(max1+max2));
    return 0;
}
