#include <stdio.h>
#include <stdlib.h>
//program for 2D array
int main(){
    int nrows = 2;
int ncols = 5;
int i, j;
char **pvow = (char **) malloc(nrows * sizeof(char *));
pvow[0] = (char *) malloc(ncols * sizeof(char));
pvow[1] = (char *) malloc(ncols * sizeof(char));
pvow[0][0] = 'A';
pvow[0][1] = 'E';
pvow[0][2] = 'I';
pvow[0][3] = 'O';
pvow[0][4] = 'U';

pvow[1][0] = 'a';
pvow[1][1] = 'e';
pvow[1][2] = 'i';
pvow[1][3] = 'o';
pvow[1][4] = 'u';
for (i = 0; i < nrows; i++) {
    for(j = 0; j < ncols; j++) {
        printf("%c ", pvow[i][j]);
    }
    printf("\n");
}
free(pvow[0]);
free(pvow[1]);
free(pvow);
}