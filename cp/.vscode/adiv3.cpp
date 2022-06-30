#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int arr[26]={0};
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]){
                continue;
            }
            else{
                arr[s[i]-'A']+=1;
            }
            
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(arr[i]>=2){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}