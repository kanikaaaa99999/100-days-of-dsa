#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, n, sizeof(int), cmp);
    
    int min_diff = INT_MAX;
    int left = 0, right = n-1;
    int best_a = arr[0], best_b = arr[1];
    
    while(left < right) {
        int sum = arr[left] + arr[right];
        int diff = abs(sum);
        
        if(diff < min_diff) {
            min_diff = diff;
            best_a = arr[left];
            best_b = arr[right];
        }
        
        if(sum == 0) break;
        else if(sum < 0) left++;
        else right--;
    }
    
    printf("%d %d\n", best_a, best_b);
    return 0;
}
