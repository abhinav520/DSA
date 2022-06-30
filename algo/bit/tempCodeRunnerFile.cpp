// #include <iostream>
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