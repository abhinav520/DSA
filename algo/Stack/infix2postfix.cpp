#include <iostream>
using namespace std;
#include <cstring>
#include "stackll.h"

bool isOperand(char c){
    switch (c)
    {
    case '+':
        return false;
    case '-':
        return false;
    case '*':
        return false;
    case '/':
        return false;
    case '^':
        return false;
    case '%':
        return false;
    case '(':
        return false;
    case ')':
        return false;
    default:
        return true;
    }
}
int inStackPre(char c){
    if(c=='+' || c=='-'){
        return 2;
    }
    else if(c=='*' || c=='/' || c=='%' ){
        return 4;
    }
    else if(c=='^'){
        return 5;
    }
    else if(c=='('){
        return 0;
    }
    return 0;
}
int outStackPre(char c){
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 3;
    case '^':
        return 6;
    case '(':
        return 7;
    case ')':
        return 0;
    default:
        return 0;
    }
}

char* convert(char* infix){
    char* postfix =new char[strlen(infix)+1];
    Stack<char> stk;
    stk.push('(');
    int i,j;
    i=j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(outStackPre(infix[i])>inStackPre(stk.stackTop()) && infix[i]!=')'){
                stk.push(infix[i++]);
            }
            else if(outStackPre(infix[i])==inStackPre(stk.stackTop())){
                stk.pop();
                i++;
            }
            else{
                char c=stk.pop();
                if(c!='('){
                    postfix[j++]=c;
                }
            }
        }
    }
    
    while(!stk.isEmpty() && stk.stackTop()!='('){
        postfix[j++]=stk.pop();
    }

    postfix[j]='\0';
    return postfix;
}

// this will not work with different associativity
// string infix2postfix(string s){
//     Stack<char> stk;
//     int len=0;
//     len=s.length();
//     string res="";
//     for(int i=0;i<len;i++){
//         if(isOperand(s[i])){
//             res+=s[i];
//         }
//         else{
//             if(stk.isEmpty()){
//                 stk.push(s[i]);
//             }
//             else{
//                 while(precedance(s[i])<=precedance(stk.stackTop())){
//                     res+=stk.pop();
//                 }
//                 stk.push(s[i]);
//             }
//         }
//     }
//     while(!stk.isEmpty()){
//         res+=stk.pop();
//     }
//     return res;
// }

int main()
{
    // string s;
    //cin>>s;
    // s="a+b*c-d/e";
    
    //char infix[]="((a+b)*c)-d^e^f";

    char infix[]="a+b*(c^d-e)^(f+g*h)-i";
    cout<<convert(infix);
    return 0;
}