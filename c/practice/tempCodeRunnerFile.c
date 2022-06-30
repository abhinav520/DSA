#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a, &b);
    printf("Before swap a = %d and b= %d\n",a,b);
    //swap without help of temporary variable
    a=a+b;
    b=a-b; //b=(a+b)-b
    a=a-b; //((a+b)-b)-(a-b)
    printf("After swap a = %d and b= %d",a,b);
    return 0;
}