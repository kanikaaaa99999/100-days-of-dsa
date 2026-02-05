#include <stdio.h>

int main() {
    int p;
    scanf("%d", &p);
    int log1[100000]; 
    for(int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    
    int q;
    scanf("%d", &q);
    int log2[100000];
    for(int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    
    int i = 0, j = 0;
    int merged[200000];  
    int k = 0;
    
    while(i < p && j < q) {
        if(log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }
    

    while(i < p) {
        merged[k++] = log1[i++];
    }
    
    
    while(j < q) {
        merged[k++] = log2[j++];
    }
    
    
    for(int idx = 0; idx < k; idx++) {
        printf("%d", merged[idx]);
        if(idx < k-1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
