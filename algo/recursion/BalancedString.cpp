#include <iostream>
#include <string.h>
using namespace std;
bool isLowerCase(char c){
    if(c>='a'& c<='z'){
        return true;
    }
    return false;
}
bool check(int st,int curr,string s,char c){
    
    char cCheck = isLowerCase(c) ? c - 32 : c + 32;
    bool flag=true;
    for(int i=st;i<=curr;i++){
        if(s[i]!=cCheck){
            flag=false;
        }
    }
    return flag;
}

void balanced(string s)
{
    int strlen = s.length();
    char cBalanced[strlen + 1];
    for(int k=2;k<(strlen);k+=2){
        for(int i=0;i<(strlen-k);i++){
            for(int j=i;j<(i+k);j++){
                int flg=1;
                if(!check(i,j+1,s,s[j+1])){
                    flg=0;
                }
                if(flg==1){
                    cout<<s.substr(i,(i+k-1))<<endl;
                }
            }
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