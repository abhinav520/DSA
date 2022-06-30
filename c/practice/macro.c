#include <stdio.h>
#define sqr(x) x*x
void print(char *c){
    while(*c!='\0'){
        printf("%c",*c);
        c++;
    }
    printf("\n");
}
int main()
{
    char *c="hello";  //compile time constant, its value cant be changed
    
     printf("%s",c);
    //c='k';
    // print(c);
    // printf("%d",sqr((5+2)));
    return 0;
}