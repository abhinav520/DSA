#include <stdio.h>
int main(){
    int a[]={4,6,8,9};
    int b=3;
    int* ptr1=&a;
    int* ptr2=&b;
    printf("%d",*(ptr1++));
    printf("\n%d",*(ptr1));
    printf("\n%d",(ptr2++));
    printf("\n%d",(ptr2++));
    // printf("\n%d",(ptr1-ptr2));
}