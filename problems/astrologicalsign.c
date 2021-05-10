#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int n, d;
    scanf("%d", &n);
    char m[4];
    char pr[n+1][14];
    for ( int i = 0; i < n; i++ ) {
        scanf("%d %s", &d, &m);
        if ( !strcmp(m, "Mar") && d >= 21 || !strcmp(m, "Apr") && d <= 20) {
            strcpy(pr[i], "Aries");
        } else if ( !strcmp(m, "Apr") && d >= 21 || !strcmp(m, "May") && d <= 20 ) {
            strcpy(pr[i], "Taurus");
        } else if ( !strcmp(m, "May") && d >= 21 || !strcmp(m, "Jun") && d <= 21 ) {
            strcpy(pr[i], "Gemini");
        } else if ( !strcmp(m, "Jun") && d >= 22 || !strcmp(m, "Jul") && d <= 22 ) {
            strcpy(pr[i], "Cancer");
        } else if ( !strcmp(m, "Jul") && d >= 23 || !strcmp(m, "Aug") && d <= 22 ) {
            strcpy(pr[i], "Leo");
        } else if ( !strcmp(m, "Aug") && d >= 23 || !strcmp(m, "Sep") && d <= 21 ) {
            strcpy(pr[i], "Virgo");
        } else if ( !strcmp(m, "Sep") && d >= 22 || !strcmp(m, "Oct") && d <= 22 ) {
            strcpy(pr[i], "Libra");
        } else if ( !strcmp(m, "Oct") && d >= 23 || !strcmp(m, "Nov") && d <= 22 ) {
            strcpy(pr[i], "Scorpio");
        } else if ( !strcmp(m, "Nov") && d >= 23 || !strcmp(m, "Dec") && d <= 21 ) {
            strcpy(pr[i], "Sagittarius");
        } else if ( !strcmp(m, "Dec") && d >= 22 || !strcmp(m, "Jan") && d <= 20 ) {
            strcpy(pr[i], "Capricorn");
        } else if ( !strcmp(m, "Jan") && d >= 21 || !strcmp(m, "Feb") && d <= 19 ) {
            strcpy(pr[i], "Aquarius");
        } else if ( !strcmp(m, "Feb") && d >= 20 || !strcmp(m, "Mar") && d <= 20 ) {
            strcpy(pr[i], "Pisces");
        }
    }
    for ( int i = 0; i < n; i++ ) {
        puts(pr[i]);
    }
    return 0;
}
