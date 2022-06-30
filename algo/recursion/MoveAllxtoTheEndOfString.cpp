#include <iostream>
using namespace std;
void moveAtEnd(string s,int len){
    static string k="";
    if(len==0){
        cout<<k;
        return;
    }
    len--;
    if(s[0]=='x'){
        k+="x";
        moveAtEnd(s.substr(1),len);
    }
    else{
        cout<<s[0] ;
        moveAtEnd(s.substr(1),len);
    }
}
int main()
{
    // string s;
    // cin>>s;
    string s = "geekxsfoksxx";
    int len=s.length();
    moveAtEnd(s,len);   
    return 0;
}