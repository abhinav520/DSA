#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string p;
	    cin.ignore();
	    getline(cin,p);
	    
	    int phr=((p[0]-'0')*10+p[1]-'0');
	    int pmin=((p[3]-'0')*10+p[4]-'0');
	    char c=p[6];
	    if(c=='P' && phr!=12){
	        phr+=12;
	    }
	    else if(c=='A' && phr==12){
	        phr=0;
	    }
	    
	    int n;
	    cin>>n;
	    cin.ignore();
	    string s[n];
	    for(int i=0;i<n;i++){
	       // cin.ignore();
	        getline(cin,s[i]);
	    }
	    for(int i=0;i<n;i++){
	        int hr1=((s[i][0]-'0')*10+s[i][1]-'0');
	        int hr2=((s[i][9]-'0')*10+s[i][10]-'0');
	        
	        int min1=((s[i][3]-'0')*10+s[i][4]-'0');
	        int min2=((s[i][12]-'0')*10+s[i][13]-'0');
	        
	        char c1=s[i][6];
	        char c2=s[i][15];
	        
	        if(c1=='P' && hr1!=12){
	            hr1+=12;
	        }
	        else if(c1=='A' && hr1==12){
	            hr1=0;
	        }
	        
	        if(c2=='P' && hr2!=12){
	            hr2+=12;
	        }
	        else if(c2=='A' && hr2==12){
	            hr2=0;
	        }
	        
	        //---comparing
	        
	        if(hr1==hr2 && hr1==phr){
	            if(min1<=pmin && pmin<=min2){
	                cout<<"1";
	            }
	            else{
	                cout<<"0";
	            }
	        }
	        
	        else if(hr1<hr2){
	            if(hr1<phr && phr<hr2){
	                cout<<"1";
	            }
	            else if((phr==hr1 && pmin>=min1) || (phr==hr2 && pmin<=min2)){
	                cout<<"1";
	            }
	            else{
	                cout<<"0";
	            }
	        }
	       
	        else if(hr1>hr2){
	            if(hr1<phr){
	                cout<<"1";
	            }
	            else if((phr==hr1 && pmin>=min1) || (phr==hr2 && pmin<=min2)){
	                cout<<"1";
	            }
	            else{
	                cout<<"0";
	            }
	        }
	        else{
	            cout<<"0";
	        }

	    }
	    cout<<endl;
        cin.ignore();
	}
	return 0;
}
