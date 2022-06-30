// #include <bits/stdc++.h>
// using namespace std;

// #define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
// #define deb(x) 			 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
// #define deb2(x, y) 		 cout << #x << "=" << x << "," << #y << "=" << y << endl
// #define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<vec[i]<<" ";} cout<<endl
// #define input(vec,n) 	 for(int i=0;i<n;i++){cin>>vec[i];}
// #define go 				 int t;cin>>t;while(t--)
// #define fastio 			 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// typedef long long int ll;


// int main()
// {
// 	go{
// 		int n;
// 		cin>>n;
// 		vector<int> v(n);
// 		input(v,n);
// 		vector<int> ans(n);
// 		unordered_map<int,set<int>> m;
// 		int cnt=0;
// 		for(int i=0;i<n;i++){
// 			m[v[i]]++;
// 		}
// 		cnt=m.size();
// 		vector<int> left;
		
// 		for(int i=0;i<n;i++){
// 			if(m[v[i]]>1){
// 				ans[i]=v[i];
// 				m[v[i]]=-1;
// 			}
// 			else if(m[v[i]]==-1) left.push_back(i);
// 			else ans[i]=v[i];
// 		}
// 		vector<int> dalna;
// 		for(auto x:m){
// 			if(x.second==0)
// 				dalna.push_back(x.first);
// 		}
// 		m.clear();
// 		cout<<cnt<<endl;
// 		auto it=left.begin();
// 		for(int i=0;i<dalna.size();i++){
// 			it=left.begin();
// 			if(dalna[i]==*it){
// 				it++;
// 			}
// 			ans[*it]=dalna[i];
// 			left.erase(it);
// 		}
// 		output(ans,n);
// 	}
// 	return 0;
// }



#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 			 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 		 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<fixed<<setprecision(4)<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 	 for(int i=0;i<n;i++){cin>>vec[i];}
#define go 				 int t;cin>>t;while(t--)
#define fastio 			 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;
#define epsilon 0.00001
const int N=7;
double arr[N];

double power(double a, int b){
    if(b==0) return 1.0;
    double res=1.0;
    for(int i=b;i>=1;i--){
        res*=i;
    }
    return res;
}
double fun(double x,vector<double> &v){
    static int j=0;
    int n=v.size();
    double f=v[n-1];
    for(int i=0;i<n-1;i++){
        f+=v[i]*power(x,n-i);
    }
    if(j!=0)
        f/=arr[j++];
    return f;   
}
double der(double x,vector<double> &v){
    static int j=0;
    int n=v.size();
    double f=v[n-2];
    for(int i=0;i<n-2;i++){
        f+=(n-i)*v[i]*power(x,n-1-i);
    }
    if(j!=0)
        f/=arr[j++];
    return f;
}

double find(double x, vector<double> &v){
    double nx=x-fun(x,v)/der(x,v);
    if(fun(nx,v)<epsilon) return nx;
    else return find(nx,v);
}
void newton(ll n,vector<double> &v){
    double root=find(-200,v);

    arr[1]=root;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+find(arr[i-1]-arr[i-2]+epsilon,v);
    }
    for(int i=0;i<n;i++){
        arr[i]=arr[i+1]-arr[i];
    }
}

int main()
{
    int ctr=1;
    while(true){
        ll n;
        cin>>n;
        if(n==0) return 0;
        vector<double> v(n+1);
        input(v,n+1);
        newton(n,v);
        cout<<"Equation "<<ctr++<<" ";
        output(arr,n);
        fill(arr,arr+6,0);
    }
    return 0;
}