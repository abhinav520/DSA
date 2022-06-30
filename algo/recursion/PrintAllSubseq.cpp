#include <iostream>
using namespace std;
void printAllSubseq(string s,string ans=""){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string reds=s.substr(1);
    printAllSubseq(reds,ans+ch);
    printAllSubseq(reds,ans);
}
int main()
{
    string s;
    // cin>>s
    s="abhinav";
    printAllSubseq(s);
    return 0;
}