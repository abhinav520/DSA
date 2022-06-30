#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int freq[26];
    for(int i=0; i<26; i++ ){
        freq[i]=0;
    }
    for(int i=0; i<s.length(); i++){
        freq[s[i]-'a']++;
    }
    char ans;
    int maxfreq=freq[0];
    for(int i=1;i<26;i++){
        if(freq[i]>maxfreq){
            maxfreq=freq[i];
            ans='a'+i;
        }
    }
    cout<<ans<<endl;
    cout<<maxfreq;
    return 0;
}