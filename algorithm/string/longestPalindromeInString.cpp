#include <iostream>
#include <string>
using namespace std;
int main(){
    string text;
    getline(cin,text);
    string temp="";
    int n=text.length();
    for(int i=0;i<n;i++){
        temp+=text[n-i-1];
    }
    int count=0, maxi=0;
    for(int i=0;i<n;i++){
        if(text[i]==temp[i]){
            count++;
        }
        else{
            maxi=max(maxi,count);
            count=0;
        }
    }
    cout<<maxi;
    return 0;
}