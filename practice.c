#include <stdio.h>
int a[26] = {0};
int main()
{
    FILE *jobs = fopen("jobs.txt", "r");
    char c;
    int count = 0;
    int num;
    scanf("%d", &num);
    while ((c = fgetc(jobs)) != -1)
    {
        if (c == '\n')
            count++;
        if (c <= 90 && c >= 65)
            a[c - 65]++;
        else if (c >= 97 && c <= 122)
            a[c - 97]++;
    }
    int i, j, temp = 0, max;
    for (i = 0; i < num; i++)
    {
        temp = 0;
        max = -1;
        for (j = 0; j < 26; j++)
        {
            if (temp < a[j])
            {
                temp = a[j];
                max = j;
            }
        }
        a[max] = 0;
    }
    printf("%d\n", count);
    printf("%d  %c", temp, max + 65);

    return 0;
}