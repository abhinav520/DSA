#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a, &b);
    //swap with help of temporary variable
    int temp;
    printf("Before swap a = %d and b= %d\n",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("After swap a = %d and b= %d",a,b);
    //swap without help of temporary variable
    a=a+b;
    b=a-b; //b=(a+b)-b
    a=a-b; //((a+b)-b)-(a-b)
    printf("After swap a = %d and b= %d",a,b);
    return 0;
}