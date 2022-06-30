/*A string is balanced if every letter in the string appears in both uppercase and lowercase, i.e “AabB” is a balanced string whereas “Ab” is not a balanced string.*/
#include <iostream>
#include <string.h>
using namespace std;
void check(char arr[], char c, int *len,bool isLowerCase, bool *isBalanced)
{
    char cCheck = isLowerCase ? c - 32 : c + 32;
    bool flag = true;
    for (int i = 0; i < *len; i++)
    {
        if (cCheck == arr[i])
        {
            // cout<<c<<"--added--1"<<c<<"--"<<*len<<endl;
            // arr[*len] = c;
            // *len+=1;
            //*isBalanced = true;
            //*ptr=i;
            //return true;
        }else {
            flag = false;
        }
    }
    if(flag){
        *isBalanced = true;
        cout<<c<<"--added--b--"<<c<<"--"<<*len<<endl;
        arr[*len] = c;
            *len+=1;
    }else{
        cout<<c<<"--added--"<<c<<"--"<<*len<<endl;
        arr[*len] = c;
            *len+=1;
    }
    //return false;
}
void balanced(string s)
{
    int strlen = s.length();
    char cBalanced[strlen + 1];
    cBalanced[0] = s[0];
    int pos = 0, len = 1;
    int* ptr= &pos;
    bool isBalanced = false;
    for (int i = 1; i < strlen; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            check(cBalanced, s[i], &len, true, &isBalanced);
            // if (check(cBalanced, s[i] - 32, len, ptr, &isBalanced))
            // {

            // }
        }
        else
        {
            check(cBalanced, s[i], &len, false, &isBalanced);
            // if (check(cBalanced, s[i] + 32, len, ptr))
            // {

            // }
        }
        if(isBalanced){
            for(int i=0;i<len;i++)
                cout<<cBalanced[i];
            break;
        }

    }
}
int main()
{
    string s;
    cin >> s;
    balanced(s);
    return 0;
}