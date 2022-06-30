#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    cout<<"\nString in upperCase\n";
    // for(int i=0;i<s.size();i++){
    //     if(s[i]>='a' && s[i]<='z'){
    //         s[i]-=32;
    //     }
    //     cout<<s[i];
    // }
    transform(s.begin(),s.end(),s.begin(),::toupper);
    cout<<s<<endl;

    cout<<"\nString in lowerCase\n";
    // for(int i=0; i<s.size();i++){
    //     if(s[i]>='A'&& s[i]<='Z'){
    //         s[i]+=32;
    //     }
    // }
    transform(s.begin(),s.end(),s.begin(),::tolower);
    cout<<s;
    return 0;
}