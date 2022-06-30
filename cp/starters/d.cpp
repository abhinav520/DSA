#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef unsigned long long int ll;
//Apply a binary search. Since the array is sorted we can find at any given index how many numbers are missing as arr[index] – (index+1). We would leverage this knowledge and apply binary search to narrow down our hunt to find that index from which getting the missing number is easier.
ll missingk(vector<ll> &vec,ll k,int n){
    int l=0,u=n-1;
        while(u>=l){
            int mid=(l+u)/2;
            ll q=vec[mid]-(mid+1);  //q=numbers_less_than_mid
            
    // If the total missing number
    // count is equal to k we can iterate
    // backwards for the first missing number
    // and that will be the answer.
            if(k==q){
                // To further optimize we check
                // missing number count is equal
                // to k. Eg: arr = [4,5,6,7,8]
                // if the previous element's
                // If you observe in the example array,
                // the total count of missing numbers for all
                // the indices are same, and we are
                // aiming to narrow down the
                // search window and achieve O(logn)
                // time complexity which
                // otherwise would've been O(n).
                if(mid>0 && vec[mid-1]-mid==k){
                    u=mid-1;
                    continue;
                }
                 // Else we return arr[mid] - 1.
                return vec[mid]-1;
            }
            else if(k<q){
                u=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(u<0){
            // In case the upper limit is -ve
            // it means the missing number set
            // is 1,2,..,k and hence we directly return k.
            return k;
        }

        ll less=vec[u]-(u+1);
        return vec[u]+k-less;
}

int main()
{
    int n;
    cin>>n;
    int tc=1;
    cin>>tc;
    vector<ll> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    
    while(tc--){
        ll k;
        cin>>k;
        cout<<missingk(vec,k,n)<<endl;
    }

    return 0;
}
