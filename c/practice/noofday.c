#include <stdio.h>
int main(){
    int month;
    printf("Enter month number: ");
    scanf("%d",&month);
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("\nThe value is %d",31);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("\nThe value is %d",30);
        break;
    case 2:
        printf("\nThe value is %d/%d",28,29);
        break;   
    default:
        printf("Invalid month");
        break;
    }
    return 0;
}