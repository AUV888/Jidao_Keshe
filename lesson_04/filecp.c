#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *source, *destination;
    if(argc<=2)
    {
        fprintf(stderr,"Missing argument\n");
        exit(1);
    }
    
    source = fopen(argv[2], "r");
    destination = fopen(argv[1], "w");
    char c;

    if (source == NULL )
    {
        printf("source ERROR\n");
    }
    else if (destination == NULL )
    {
        printf("destination ERROR\n");
    }
    else
    {
        c = fgetc(source);
        while (!feof(source))
        {
            fputc(c, destination);
            c = fgetc(source);
        }
        fclose(source);
        fclose(destination);
    }
    return 0;
}