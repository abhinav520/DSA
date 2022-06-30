// // #include <iostream>
// // #include <vector>
// // using namespace std;

// // int main() {
// //     int t;
// //     cin>>t;
// //     while(t--){
// //         int n,m,k;
// //         cin>>n>>m>>k;
// //         vector<vector<int>> vect;
// //         for(int i=0;i<n;i++){
// //             for(int j=0;j<m;j++){
                
// //             }
// //         }
// //         for (int i = 0; i < vect.size(); i++)
// //         {
// //             for (int j = 0; j < vect[i].size(); j++)
// //             {
// //                 cout << vect[i][j] << " ";
// //             }   
// //             cout << endl;
// //         }
// //     }
// // 	return 0;
// // }
// #include <iostream>

// using namespace std;
// const int m=1e9+7;

// int gcd(int a, int b){
//     if(a==0){                 //Euclidean algo          
//         return b;               //gcd(r,0)=r
//     }
//     if(b==0){
//         return a;
//     }
//     if(a==b){
//         return a;
//     }
//     if(a>b){
//         return gcd(b,a%b);    //gcd(a,b)=gcd(b,remainder)
//     }                        
//     else
//         return gcd(a,b%a);
// }
// int modulorInverse(int b, int m)
// {
//     int m1 = m;
//     int y = 0, x = 1;
 
//     if (m == 1)
//         return 0;
 
//     while (b > 1) {
 
//         int q = b / m;
//         int t = m;
 
//         m = b % m, b = t;
//         t = y;
 
//         y = x - q * y;
//         x = t;
//     }

//     if (x < 0)
//         x += m1;
 
//     return x;
// }
// int main() {
//     int t;
//     cin>>t;
//     while(t--){
// 		int n,r;
// 		cin>>n>>r;
// 		int p,q;
// 		int d=gcd(n,r);
// 		p=n/d;
// 		q=r/d;
// 		cout<<(p*modulorInverse(q,m))%m;
// 	}
// 	return 0;
// }
#include <iostream>

using namespace std;
const int m=1e9+7;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}

// int modulorInverse(int b, int m)
// {
//     int m1 = m;
//     int y = 0, x = 1;
 
//     if (m == 1)
//         return 0;
 
//     while (b > 1) {
 
//         int q = b / m;
//         int t = m;
 
//         m = b % m, b = t;
//         t = y;
 
//         y = x - q * y;
//         x = t;
//     }

//     if (x < 0)
//         x += m1;
 
//     return x;
// }

int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
  
int modulorInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    {  
        int res = (x%m + m) % m; 
        return res;
    } 
} 
  



int main() {
    int t;
    cin>>t;
    while(t--){
		int n,r;
		cin>>n>>r;
		int p,q;
		int d=gcd(n,r);
		q=n/d;
		p=r/d;
		cout<<(modulorInverse(q,m))<<endl;
		cout<<(((p%m)*(modulorInverse(q,m)%m))%m)<<endl;
		
	}
	return 0;
}