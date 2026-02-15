#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int m, n;
    int matrix[MAX_SIZE][MAX_SIZE];
    int sum = 0;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int limit = (m < n) ? m : n;
    for(int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }
    printf("%d\n", sum);
    return 0;
}
