#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d", &a);
        b = 1;
        for (int j = 1; j <= a; j++){
            printf("%d ", b);
            b++;
        }

        b -= 2;
        for (int j = 1; j < a; j++){
            printf("%d ", b);
            b--;
        }
        printf("\n");
    }
}