#include <iostream>
#include <cctype>
using namespace std;
int main(){
    // int isLowerCaseVowel,isUpperCaseVowel;
    cout<<"enter a alaphabet: ";
    char s;
    cin>>s;
    char k= tolower((int) s);
    // isLowerCaseVowel=(s=='a'||s=='e'||s=='i'||s=='o'||s=='u');
    // isUpperCaseVowel=(s=='A'||s=='E'||s=='I'||s=='O'||s=='U');
    // cout<<isUpperCaseVowel;
    // if(isLowerCaseVowel||isUpperCaseVowel){
    //     cout<<"character is vowel";
    // }
    // else{
    //     cout<<"character is consonant";
    // }
    switch(k){
    case('a'):
        cout<<"character is vowel";
        break;
    case('e'):
        cout<<"character is vowel";
        break;
    case('i'):
        cout<<"character is vowel";
        break;
    case('o'):
        cout<<"character is vowel";
        break;
    case('u'):
        cout<<"character is vowel";
        break;
    default:
        cout<<"character is symbol or number";
    }

    
    return 0;
}