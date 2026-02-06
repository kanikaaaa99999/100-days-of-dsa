#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100000]; 
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    
    int write = 0;
    for(int read = 1; read < n; read++) {
        if(arr[read] != arr[write]) {
            write++;
            arr[write] = arr[read];
        }
    }
    
    int unique_count = write + 1;
    
   
    for(int i = 0; i < unique_count; i++) {
        printf("%d", arr[i]);
        if(i < unique_count - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
