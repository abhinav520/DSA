// #include <stdio.h>
// int main()
// {
//     FILE *ptr=0;
//     ptr= fopen("mytext.c","r");
//     // char *c=fgetc(ptr);
//     // printf("The character i read was %c\n",c);
//     // c=fgetc(ptr);
//     // printf("The character i read was %c\n",c);
//     char * c = fgetc(ptr);
//     printf("The character I read was %c\n", c );
//     c = fgetc(ptr);
//     printf("The character I read was %c\n", c );

//     // char str[4];
//     // fgets(str, 5, ptr);
//     // printf("The string is %s\n", str);

//     // fputc('o',ptr);
//     // fputs("this is harry",ptr);

//     fclose(ptr);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr=NULL;
    // Declare a pointer to a file
    fptr = fopen("mytxt.txt", "r");
    if (fptr == NULL)
    {
        printf("Error in creating file");
        exit(-1);
        // Quit the function
    }
    else{
        char c;
        c=fgetc(fptr);
        printf("The character i read was %c\n",c);
        c=fgetc(fptr);
        printf("The character i read was %c\n",c);
    }

    fclose(fptr);
    return 0;
}

// int main()
// {
// FILE *fptr;
// int c;
// /* Open file and check it is open */
// if( (fptr=fopen("abc.txt", "r") )==NULL)
// {
// printf("This file doesn't exist\n");
// exit(-1);
// }
// while ((c=fgetc(fptr))!= EOF)
// {
// printf ("%c",c);
// }
// fclose(fptr);
// }