#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// string swap(string str, int s_ind, int e_ind){
//     char c=str[e_ind];
//     str[e_ind]=str[s_ind];
//     str[s_ind]=c;
//     return str;
// }

void permute(string str, int i, int n) 
{
    static int count=0;
    if(i==n){
        count++;
        cout<<str<<endl;
        return;
    }
    for(int j=i;j<=n;j++){
        if(i!=j && str[i]==str[j]){
            continue;
        }
        swap(str[i],str[j]);
        permute(str,i+1,n);
       // swap(str[i],str[j]);  //backtrack
    }
}


void stlpermute(string str,int i,int n){
    sort(str.begin(),str.end());
    do{
        cout<<str<<endl;
    }while(next_permutation(str.begin(),str.end()));
}

void permuteStr(string &s,string ans=""){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        permuteStr(ros,ans+ch);
    }
}

int main()
{
    string str = "ACA";
    int n = str.size();
    permuteStr(str);
    cout<<endl;
    permute(str, 0, n - 1);
    return 0;
}