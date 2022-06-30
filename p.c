#include <stdio.h>
void foo(int* p){
    printf("%d\n",*p);
}
int main()
{
    int a[]={10,20,30,40,50,60};
    int* ptr1=a;
    int* ptr2=a+5;
    printf("%d, %d\n",ptr2,ptr1);
    printf("%d, %d\n",(char*)ptr2,(char*)ptr1);
    printf("x=%d, y=%d",ptr2-ptr1,(char*)ptr2-(char*)ptr1);
    
    return 0;
}
