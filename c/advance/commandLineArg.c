#include <stdio.h>
//Command-line arguments are given after the name of the program in command-line shell of Operating Systems.


//argc--argument count== is int and stores number of command-line arguments passed by the user including the name of the program.
//argv--argument vector== is array of character pointers listing all the arguments.
//If argc is greater than zero,the array elements from argv[0] to argv[argc-1] will contain pointers to strings.
//Argv[0] is the name of the program , After that till argv[argc-1] every element is command -line arguments

//They are passed to main() function.
//They are parameters/arguments supplied to the program when it is invoked.
//They are used to control program from outside instead of hard coding those values inside the code.
//argv[argc] is a NULL pointer.
//Default value of argc is 1 and default value of argv[0] is name of the program

//int main(int argc, char **argv){}
int main(int argc, char const *argv[])
{
    printf("\nProgram name is %s\n",argv[0]);
    if(argc==1)
    {
        printf("No Extra Command Line Argument Passed Other Than Program Name\n");
    }
    if(argc>=2)
    {
        printf("\nNumber Of Arguments Passed: %d\n",argc);
        printf("----Following Are The Command Line Arguments Passed----\n");
        for(int i=1;i<argc;i++)
        {
            printf("argv[%d]-%s\n",i,argv[i]);
        }
    }
    return 0;
}
