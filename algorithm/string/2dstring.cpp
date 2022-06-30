//Print a string which is the longest common prefix of all the given strings.
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	if(n==1){
		cout<<s[0];
		return 0;
	}
	sort(s,s+n);
	string a=s[0];
	string b=s[n-1];
	string res="";
	int i=0;
	int k=min(a.size(),b.size());
	while( (i<k) && (a[i]==b[i]) ){
		res+=a[i];
		i++;
	}
	cout<<res;
	return 0;
}