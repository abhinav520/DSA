#include <iostream>
using namespace std;
const int N=26;
int hsh[N];
string removeDup(string s){
    string reds="";
    for(int i=0;i<s.length();i++){
        if(hsh[s[i]-'a']==0){
            reds.push_back(s[i]);
            hsh[s[i]-'a']=1;
        }
    }
    return reds;
}
int main()
{
    // string s;
    // cin>>s;
    string s="aaaabbbceeddd";
    cout<<removeDup(s);
    return 0;
}