#include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}

int atoi(string str)
{
    int res=0, i=0;
    int sign=1;
    while(str[i]==' '){
        i++;
    }
    if(str[i]=='-' || str[i]=='+'){
        sign= (str[i]=='-')?-1:1;
        i++;
    }
    for(;str[i]!='\0';i++){
        if(str[i]>='0' && str[i]<='9'){
            if(res*10>=INT_MAX){
                return ((sign==1)?INT_MAX:INT_MIN);
            }
            else{
                res=res*10+(str[i]-'0');
                
            } 
        } 
        else{
            return -1;
        }
    }
    return res*sign;
}