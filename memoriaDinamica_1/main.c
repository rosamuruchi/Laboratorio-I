#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;

    p= (int*) malloc(sizeof(int));

    if(p==NULL)
    {
        printf("No hay memoria!\n");
    }
    else
    {
        *p=5;
        printf("%d",*p);
    }

    free(p);

    return 0;
}
