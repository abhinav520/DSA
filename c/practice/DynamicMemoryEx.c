#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size, i = 1;

    while (i <= 3)
    {
        printf("Employee %d: Enter the number of characerters:",i);
        scanf("%d",&size);
        char* ptr= (char*)malloc((size+1)*sizeof(char));
        printf("Enter the employee id:");
        scanf("%s",ptr);
        printf("The employee id is %s\n",ptr);
        free(ptr);
        i++;
    }

    return 0;
}