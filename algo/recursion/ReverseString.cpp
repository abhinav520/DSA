#include <iostream>
#include <string.h>
using namespace std;
/*
string reverse( string s,int k=0 )
{
    if(k==s.length() ){
        return s;
    }
    return reverse( (s.substr(1) + s[0]),(k+1));
}
*/
void reverse(string str,int k=0)
{
    if(k==str.length()){
        return;
    }
    reverse(str,k+1);
    cout<<(str[k]);
}

int main()
{
    string s;
    cin>>s;
    //int n= s.length();
    reverse(s);
    return 0;
}