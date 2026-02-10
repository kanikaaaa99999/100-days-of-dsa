#include <stdio.h>

int main() {
    char s[1000];
    scanf("%s", s);
    
    int left = 0;
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    int right = len - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            printf("NO\n");
            return 0;
        }
        left++;
        right--;
    }
    
    printf("YES\n");
    return 0;
}
