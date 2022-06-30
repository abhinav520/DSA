// #include <bits/stdc++.h>
// using namespace std;

// #define deb(x) 		cout << #x << "=" << x << endl
// #define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
// typedef long long int ll;

// void solve()
// {
//     int k;
//     cin>>k;
    
// 	ll res=0;
//     vector<int> v;
//     int a=4*k+1;
// 	res+=a;

//     for(int i=3;i*i<=a;i+=2){
//         if(a%i==0){
//             v.push_back(i);
//             if(i!=(a/i))
//             v.push_back(a/i);
//         }
//     }
//     //for(int x:v) cout<<x<<endl;
    
//     int arr[2*k];
//     int s=1;
//     for(int i=0;i<2*k;i++){
//         arr[i]=1;
//     }
//     for(int x:v){
//         s=x/2;
//         if((2*s+1)%x==0 && x>arr[s]){
//             while(s<2*k){
//                 if(x>arr[s]) arr[s]=x;
//                 s+=x;
//             }
//         }
//     }
//     for(int i=1;i<2*k;i++){
//         res+=arr[i];
//     }
//     // int l=2*k-1;
//     // int b;
//     // int ct=0;
//     // for(int x:v){
//     //     b=l/x;
//     //     ct+=b;
//     //     res+=(l/x)*x;
//     // }
//     // res+=(l-ct);
    
// //     int flag=1;
// //     for(int j=3;j<(4*k+1);j+=2){
// // 		flag=1;
// //         for(int x:v){
// //             if(j%x==0){
// //                 res+=x;
// //                 flag=0;
// //                 break;
// //             }
// //         }
// //         if(flag){
// //             res+=1;
// //         }
// //     }
//     cout<<res<<endl;
    
// }


// int main()
// {
   

//     int tc=1;
//     cin>>tc;

//     while(tc--){
//         solve();
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;
ll dd[1000];
ll res[1000501];


void solve()
{
    int k;
    cin>>k;
    cout<<res[k]<<endl;
}


int main()
{
    ll s=5;
    ll d=3;
    ll c=0;
    dd[c++]=2;
    dd[c++]=5;
    while(c<=999){
        int x=2;
        if(x==2){
            d+=3;
            s+=d;
            dd[c++]=s;
            x--;
        }
        if(x==1){
            d+=1;
            s+=d;
            dd[c++]=s;
            x=2;
        }
    }
    // for(int i=0;i<1001;i++){
    //     cout<<dd[i]<<endl;
    // }


    int j;
    int m=1;
    int r=0;
    int q=2;
    int flag=1;
    while(m<1000){
        j=3;r=0;
        for(int i=0;i<2*m;i++){
            q=j;
            if((dd[i])%j==0){
                res[m]+=j;
                r+=j;
            }
            else{
                if((q/j)>1){
                    q/=j;
                    while(q>1){
                        if((dd[i])%q==0){
                            res[m]+=q;
                            r+=q;
                            flag=0;
                        }
                    }
                }
                if(flag){
                    res[m]+=1;
                    r+=1;
                }
            }
            j+=2;
            dd[i]+=1;
            flag=1;
        }
        cout<<r<<endl;
        m++;
    }
    

    // for(int i=1;i<10;i++){
    //     cout<<res[i]<<endl;
    // }
    

    // int tc=1;
    // cin>>tc;

    // while(tc--){
    //     solve();
    // }
    
    
  
    return 0;
}