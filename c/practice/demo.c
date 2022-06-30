#include <stdio.h>
int main(){
    int num1,num2;
    char op;
    
    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);    
    printf("Enter operator:");
    // op= getche();
    scanf("\n%c",&op);
    // printf("%c",op);
    int value;
    switch (op)
    {
    case '+':
        value = num1+num2;
        break;
    case '-':
        value=num1-num2;
        break;
    case'/':
        value=num1/num2;
        break;
    case '*':
        value = num1*num2;
        break;
    
    default:
        printf("Invalid operator!");
        break;
    }
    printf("\nThe value is %d",value);
    return 0;

}