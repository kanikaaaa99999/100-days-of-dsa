#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term* next;
};

struct Term* createTerm(int c, int e) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = c;
    newTerm->exp = e;
    newTerm->next = NULL;
    return newTerm;
}

void insert(struct Term** head, int c, int e) {
    struct Term* newTerm = createTerm(c, e);
    if (*head == NULL) {
        *head = newTerm;
        return;
    }
    struct Term* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = newTerm;
}

// Bubble sort by descending exponent
void sortPolynomial(struct Term** head) {
    if (*head == NULL) return;
    
    int swapped;
    do {
        swapped = 0;
        struct Term* current = *head;
        while (current->next != NULL) {
            if (current->exp < current->next->exp) {
                // Swap data
                int temp_coeff = current->coeff;
                int temp_exp = current->exp;
                current->coeff = current->next->coeff;
                current->exp = current->next->exp;
                current->next->coeff = temp_coeff;
                current->next->exp = temp_exp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

void printPolynomial(struct Term* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    
    struct Term* current = head;
    int first = 1;
    while (current != NULL) {
        if (!first) {
            printf(" + ");
        }
        
        printf("%dx^%d", current->coeff, current->exp);
        
        first = 0;
        current = current->next;
    }
    printf("\n");
}

void freePolynomial(struct Term** head) {
    struct Term* current = *head;
    while (current != NULL) {
        struct Term* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Term* poly = NULL;
    
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insert(&poly, coeff, exp);
    }
    
    sortPolynomial(&poly);
    printPolynomial(poly);
    
    freePolynomial(&poly);
    return 0;
}
