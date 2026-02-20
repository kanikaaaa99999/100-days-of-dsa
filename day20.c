#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0, count = 0;

    int hash[2 * MAX + 1] = {0};
    int offset = MAX;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(prefixSum == 0) {
            count++;
        }

        if(hash[prefixSum + offset] > 0) {
            count += hash[prefixSum + offset];
        }

        hash[prefixSum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}