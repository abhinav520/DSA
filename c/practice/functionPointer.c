#include <stdio.h>
void print(char* name){
    printf("Hello %s\n",name);
}
int add(int a,int b){
    int c=a+b;
    return c;
}
int main(){
   int (*func_ptr)(int,int);   //--> initialization of function pointer
/*
    //Function can be(possible) declared within the main() only. But, function definition should be outside of the main(), after the main() function body.
    int *func_ptr(int,int);     //--> declaring a function that would return int*
*/

   // func_ptr=&add;
    func_ptr=add;            //function name will return us pointer
    int c=(*func_ptr)(2,3);  //derferencing and executing the function
    int d=func_ptr(0,3);     //alias of above

    void (*ptr)(char*);
    ptr=print;
    ptr("Abhinav");

    printf("c--%d\n",c);
    printf("d--%d\n",d);
    return 0;
}