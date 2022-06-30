#include <stdio.h>
int main(){
    int a=45;
    int* ptr= &a;
    int* ptr2= NULL;
    printf("The address of pointer to a is %p \n ",&ptr);
    printf("The value of a %d \n ",*ptr);
    printf("The address of a %x \n ",ptr);
    printf("The address of a %p \n ",&a);
    printf("The address of some garbage is %p \n ",ptr2);
    printf("The value of ptr2 %d \n ",ptr2);
    printf("The value of a %d \a\n ",a);
}