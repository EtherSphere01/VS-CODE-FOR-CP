#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char a[101];
    char b[101];
    char c[101];
    scanf("%s %s %s", a, b, c);

    int length = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        length++;
    }

    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (a[i] == b[i] && b[i] == c[i] && c[i] == a[i])
        {
            continue;
        }
        else if (a[i] != b[i] && b[i] != c[i] && c[i] != a[i])
        {
            count += 2;
        }
        else
        {
            count++;
        }
    }
    printf("%d\n", count);
}