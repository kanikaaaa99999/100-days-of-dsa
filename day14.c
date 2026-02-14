#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int n;
    int matrix[MAX_SIZE][MAX_SIZE];
    int isIdentity = 1;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) {
                    isIdentity = 0;
                }
            } else {
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                }
            }
        }
    }

    if(isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}
