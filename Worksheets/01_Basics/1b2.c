#include <stdio.h>

int main(void) {
    int count, i;
    scanf("%d", &count);

    /* Replaces while loop with for loop */
    for(i = 0; i < count; i++) {
        printf("%d ", i);
    }

    return 0;
}
