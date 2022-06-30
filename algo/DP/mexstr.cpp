#include <iostream>
#include <set>
using namespace std;

int subseq(string s,set<string> vec){
    if(s.size()==0){
        vec.insert("0");
        return 1;
    }
    int smal=subseq(s.substr(1),vec);
    set<string>::iterator it=vec.begin();
    for(int i=0;i<smal;i++){
		advance(it,(i+smal));
        vec.insert(s[0]+ *it);
    }
    return 2*smal;
}

int main() {
	// int t;
	// cin>>t;
	// while(t--){
	//     string s;
	//     cin>>s;
	//     set<string> ar;
	//     int sze=subseq(s,ar);
	//    // for(int i=1;i<sze;i++){
	//    //     cout<<ar[i]<<" ";
	//    // }
	//    for(auto x:ar){
	//        cout<<x<<" ";
	//    }
	// }
	int c(1);
	cout<<c;
	return 0;
}
