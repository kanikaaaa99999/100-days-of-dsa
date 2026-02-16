#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int n;
    int arr[MAX_SIZE];
    int freq[MAX_SIZE] = {0};
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i < n; i++) {
        if(freq[i] == 0) {
            int count = 1;
            for(int j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    freq[j] = -1;
                }
            }
            printf("%d:%d ", arr[i], count);
            freq[i] = 1;
        }
    }
    printf("\n");
    
    return 0;
}
