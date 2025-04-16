#include <stdio.h>

int main()
{
    FILE *fptr;
    fptr = fopen("./bin/data.txt", "w");
    if (fptr == NULL)
    {
        printf("CANNOT OPEN FILE\n");
    }
    else
    {
        char c;
        while ((c = getchar()) != EOF)
        {
            fputc(c,fptr);
        }
        fclose(fptr);
    }
}