#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int siz[100000];
// int rnk[100000];

void make_set(int v){
    parent[v]=v;
    siz[v] = 1;     //when use siz
    // rnk[v]=0;
}

int find_set(int v){ //findParentroot
    if(v==parent[v]) return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(siz[a]<siz[b])
        // if(rnk[a]<rnk[b])
            swap(a,b);
        parent[b]=a;
        siz[a] += siz[b];   //when use siz remove next lines
        // if(rnk[a]==rnk[b])    
        //     rnk[a]++;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        make_set(i);
    }
    int q;
    cin>>q;
    int no_of_cycle=0;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(find_set(a)==find_set(b)){
            no_of_cycle++;
            // cout<<"cycle fond at endge "<<a<<" "<<b<<endl;
        } 
        else{
            union_sets(a,b);
        }  
    }
    cout<<no_of_cycle<<endl;
    return 0;
}