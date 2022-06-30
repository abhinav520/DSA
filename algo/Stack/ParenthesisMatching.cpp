//        /-\ |; |-| ! |\| @ \/    & ! |\| {-: |-|
#include <iostream>
#include <string>
#include <cstring>
#include "stackll.h"
using namespace std;
bool isParenthesisBal(string s,Stack<char>* stk){
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            (*stk).push(s[i]);
        }
        else if(s[i]==')'){
            if(stk->isEmpty()){
                return false;
            }
            (*stk).pop();
        }
    }
    return (stk->isEmpty()) ? true: false;
}

//               -------------------
//Ascii code of |'('=40  |   ')'=41 |   -->     <50        :    diff=1
//              |'['=91  |   ']'=93 |   -->     >50 & <100 :    diff=2
//              |'{'=123 |   '}'=125|   -->     >100       :    diff=2
//               -------------------
bool isAllParenthesisBaln(char c[]){
    // Stack<char> stk1,stk2,stk3;
    // for(int i=0;i<strlen(c);i++){
    //     if(c[i]=='('){
    //         stk1.push(c[i]);
    //     }
    //     else if(c[i]=='['){
    //         stk2.push(c[i]);
    //     }
    //     else if(c[i]=='{'){
    //         stk3.push(c[i]);
    //     }
    //     else if(c[i]==')'){
    //         if(stk1.isEmpty()){
    //             return false;
    //         }
    //         else if(stk1.pop()!='('){
    //             return false;
    //         }
    //     }
    //     else if(c[i]==']'){
    //         if(stk2.isEmpty()){
    //             return false;
    //         }
    //         else if(stk2.pop()!='['){
    //             return false;
    //         }
    //     }
    //     else if(c[i]=='}'){
    //         if(stk3.isEmpty()){
    //             return false;
    //         }
    //         else if(stk3.pop()!='{'){
    //             return false;
    //         }
    //     }
    // }
    // return (stk1.isEmpty() && stk2.isEmpty() && stk3.isEmpty()) ? true: false;

    Stack<char> stk;
    for(int i=0;i<strlen(c);i++){
        if(c[i]=='(' || c[i]=='{' || c[i]=='['){
            stk.push(c[i]);
        }
        else if(c[i]==')' || c[i]=='}' || c[i]==']'){
            if(stk.isEmpty()){
                return false;
            }
            else{
                int chk=0;
                if(c[i]==')'){
                    chk+=c[i]-1;
                }
                else if(c[i]=='}'){
                    chk+=c[i]-2;
                }
                else{
                    chk+=c[i]-2;
                }
                if(chk==stk.stackTop()) stk.pop() ;

            }
        }
    }
    return (stk.isEmpty())? true:false;
}

int main()
{
    Stack<char> stk;
    // string s;
    // cin>>s;
    // s="(((a+b)*(c-d))";
    // if(isParenthesisBal(s,&stk)){
    //     cout<<"Balanced";
    // }
    // else cout<<"Unbalanced";


    char c[]="{([a+b]*[c-d])/e}";
    if(isAllParenthesisBaln(c)){
        cout<<"Balanced";
    }
    else cout<<"Unbalanced";

    return 0;
}