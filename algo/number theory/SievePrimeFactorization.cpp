#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<int> factors(int n){
    vector<int> v;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            v.push_back(i);
            n/=i;
        }
    }
    if(n>1) v.push_back(n);
    return  v;
}

map<int,int> prime(int n){
	int t=(int)sqrt(n);
    map<int,int> m;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
			m[i]++;
			n/=i;
		}
    }
	if(n>1) m[n]++;
    return m;
}

void sievePrimeFactor(int n)
{
	//AIM: create spf array with index as num and value as smallest prime factor
	int spf[n+1];  
	for(int i=2;i<=n;i++){
		spf[i]=i;
	}
	for(int i=2;i<=n;i++){
		if(spf[i]==i){
			for(int j=i*i;j<=n;j+=i){
				if(spf[j]==j){
					spf[j]=i;
				}
			}
		}
	}
	while(n!=1){
		cout<<spf[n]<<" ";
		n/=spf[n];
	}
	cout<<endl;

}

int main() {
	int n;
	cin >> n;
	sievePrimeFactor(n);

	// vector<int> vec=factors(number);
    // for(auto x:vec){
    //     cout<<x<<" ";
    // }

	map<int,int> m=prime(24);
	for(auto c:m){
		cout<<c.first<<"-"<<c.second<<endl;
	}


	return 0;
}

