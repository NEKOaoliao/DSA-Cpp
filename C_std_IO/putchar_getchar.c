#include "stdio.h"

int main()
{

    int c;

    printf("Enter a value :");
    // c = getchar();
    scanf("%d", &c);

    printf("\nYou entered: ");
    // putchar(c);
    printf("%d", c);

    return 0;
}