#include <stdio.h>

int main(int argc, char const *argv[]) {
    int board[5][5];
    char line[5];
    int count = 0;
    for ( int i = 0; i < 5; i++ ) {
        scanf("%s", line);
        for ( int j = 0; j < 5; j++ ) {
            if ( line[j] == '.' ) {
                board[i][j] = 0;
            } else {
                board[i][j] = 1;
                count++;
            }
        }
    }
    if ( count != 9 ) {
        printf("invalid");
        return 0;
    }
    int valid = 1;
    for ( int i = 0; i < 5; i++ ) {
        for ( int j = 0; j < 5; j++ ) {
            if ( board[i][j] == 1 ) {
                // left
                if ( j > 1 ) {
                    // top
                    if ( i > 0 ) {
                        if ( board[i-1][j-2] ) {
                            valid = 0;
                            break;
                        }
                    }
                    // bottom
                    if ( i < 4 ) {
                        if ( board[i+1][j-2] ) {
                            valid = 0;
                            break;
                        }
                    }
                }
                // right
                if ( j < 3 ) {
                    // top
                    if ( i > 0 ) {
                        if ( board[i-1][j+2] ) {
                            valid = 0;
                            break;
                        }
                    }
                    // bottom
                    if ( i < 4 ) {
                        if ( board[i+1][j+2] ) {
                            valid = 0;
                            break;
                        }
                    }
                }
                // top
                if ( i > 1 ) {
                    // left
                    if ( j > 0 ) {
                        if ( board[i-2][j-1] ) {
                            valid = 0;
                            break;
                        }
                    }
                    // right
                    if ( j < 4 ) {
                        if ( board[i-2][j+1] ) {
                            valid = 0;
                            break;
                        }
                    }
                }
                // bottom
                if ( i < 3 ) {
                    // left
                    if ( j > 0 ) {
                        if ( board[i+2][j-1] ) {
                            valid = 0;
                            break;
                        }
                    }
                    // right
                    if ( j < 4 ) {
                        if ( board[i+2][j+1] ) {
                            valid = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    if ( valid ) {
        printf("valid");
    } else {
        printf("invalid");
    }
    return 0;
}
