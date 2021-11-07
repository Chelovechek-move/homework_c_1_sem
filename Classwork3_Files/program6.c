#include <stdio.h>

int main()
{
    int c = 0;
    FILE* f = fopen("test.txt", "r");

    fseek(f, 9, SEEK_SET);
    fscanf(f, "%d", &c);

    printf("%d", c);
    
    fclose(f);
}