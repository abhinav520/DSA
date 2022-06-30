#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
bool f(int x,int y){
    return x>y;
}
void vectorDemo(){
//Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time

    //vector declaration
    vector<int> vec{11,2,3,14};

    // for(int i=0;i<4;i++){
    //     // cin>>vec[i];   -->this is wrong
    //     int t;
    //     cin>>t;
    //     vec.push_back(t);
    // }

    
    cout<<vec[1]<<endl;
    sort(vec.begin(),vec.end());    //this(sort) not in vector header file but in algorithm header file
    //O(nlogn)
    // for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
    //     cout<<*it<<" ";
    // }
    cout<<vec[2];
    for(int i=0;i<4;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    //2,3,11,14
    bool present;
    present=binary_search(vec.begin(),vec.end(),11);  //true;
    cout<<present<<endl;
    present=binary_search(vec.begin(),vec.end(),4);   //false
    cout<<present<<endl;

    for(int i=0;i<4;i++){
        vec.push_back(100);
    }
    vec.push_back(123);
    //2,3,11,14,100,100,100,100,123

//The auto keyword specifies that the type of the variable that is being declared will be automatically deducted from its initializer. In case of functions, if their return type is auto then that will be evaluated by return type expression at runtime.

    auto it1=lower_bound(vec.begin(),vec.end(),100);  //>=   //here 1st 100
    //auto se compiler khud samajh jata hai kon sa type hai
    vector<int>::iterator it2=upper_bound(vec.begin(),vec.end(),100);  //>    //here 123
    //above line is the traditional way of writing
    cout<<*it1<<"  "<<*it2<<endl;  //100   123
    cout<<it2-it1<<endl;
    sort(vec.begin(),vec.end(),greater<int>());
    //vector<int>::iterator it3;
    // for(int it3:vec){                       //advance style of writing
    //     cout<<it3<<" ";                       //you cannot change value in this style use reference
    // }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    for(int &it3:vec){       //reference                   
        it3++;  
        cout<<it3<<" ";                    
    }
    cout<<endl;
    for(auto it3:vec){                       
        cout<<it3<<" ";                      
    }
}


void setDemo(){
//Sets are a type of associative containers in which each element has to be unique, because the value of the element identifies it. The value of the element cannot be modified once it is added to the set, though it is possible to remove and add the modified value of that element.

    set<int> s2;
    // vector<int> vecx{10,-1,20,-1,100,5};
    
    s2.insert(10);
    s2.insert(-1);
    s2.insert(20);
    s2.insert(-1);         // This will not add as -1 is alredy present in the set
    s2.insert(100);
    s2.insert(5);
    //-1,10,20,100

    auto iter=s2.find(10);
    if(iter==s2.end()){
        cout<<"10 not found!";
    }
    else{
        cout<<*iter<<"\n";
    }

    auto iter1=s2.lower_bound(10);
    auto iter2=s2.upper_bound(15);
    cout<<*iter1<<"--"<<*iter2<<endl;
    set<int> s3;
    s3.insert(s2.begin(),s2.end());
    //copying the the value of s2 in s1;
    set<int, greater<int>> s1(s2.begin(),s2.end());    //set will form in decreasing order
    for(int x:s1){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int x:s3){
        cout<<x<<" ";
    }
    cout<<endl;

    s2.erase(++s2.begin());
    s2.insert(25);
    s2.insert(2);
    for(int x:s2){
        cout<<x<<" ";
    }
    cout<<endl;
    s2.erase(s2.begin(),s2.find(20));
    for(int x:s2){
        cout<<x<<" ";
    }
    cout<<endl;
    s2.clear();
    cout<<"s2-Size: "<<s2.size()<<" max_size:"<<s2.max_size();
    cout<<endl;
}


void mapDemo(){
//Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have same key values.Internally, the elements in a map are always sorted by its key. Maps are mainly implemented as binary search trees.

    map<int,int> A;
    A[1]=10;
    A[20]=58;
    A[3]=5;
    A[-5]=2;
    auto itr=A.begin(); 
    while(itr!=A.end()){
        cout<<itr->first<<"\t"<<itr->second<<endl;
        itr++;
    }
    cout<<"-----------"<<endl;
    map<char,int> cnt;
    string x="Abhinav Singh";
    for(char c:x){
        cnt[c]++;
    }
    map<char,int>::iterator citr=cnt.begin();
    int i=cnt.size();
    while(i--){
        cout<<citr->first<<"--"<<citr->second<<endl;
        citr++;
    }
    cout<<"-----------"<<endl;
    map<int,int>::iterator iter;

    map<int,int> map1;
    map1.insert(pair<int,int>(1,40));
    map1.insert(pair<int,int>(2,30));
    map1.insert(pair<int,int>(3,50));
    map1.insert(pair<int,int>(6,35));
    auto it=map1.insert(pair<int,int>(5,54));
    map1.insert({7,88});
    auto ite=map1.find(7);    //it and ite are different
    map1.insert(ite,{8,56});

    
    map<int,int,greater <int>> map2;
    map2.insert(map1.begin(),map1.end());

    if(map1==A){    //can be compared if map1 and map2 are of same type aand order 
        cout<<true;
    }
    else cout<<false;

    map1.swap(A);          //for swaping type must be same
    //swap(map1,A)
    for(auto x:map1){         //x is pair
        cout<<x.first<<"--"<<x.second<<endl;
    }
    cout<<"-----------"<<endl;
    for(auto x:map2){         //x is pair
        cout<<x.first<<"--"<<x.second<<endl;
    }

    cout<<"LowerBound\t: "<<map2.lower_bound(3)->first<<"--"<<map2.lower_bound(3)->second;
    cout<<"\nUpperBound\t: "<<map2.upper_bound(6)->first<<"--"<<map2.upper_bound(6)->second<<endl;
    map1.erase(4);
    cout<<"Size: "<<map1.size()<<"\nMaxSize: "<<map1.max_size()<<endl;
    
    map1.clear();
    if(map1.empty()){
        cout<<"Map1 is empty";
    }
}

void PowerofSTL(){
// finding a given number contain in which interval or it is not contained in any interval
    set<pair<int,int>> Set;
    Set.insert({1,5});
    Set.insert({10,25});
    Set.insert({100,400});
    Set.insert({30,90});
    int x=401;
    auto it=Set.upper_bound({x,INT_MAX});
    //set<pair<int,int>>::iterator it=Set.upper_bound({x,INT_MAX});
    if(it==Set.begin()){
        cout<<"It is not present in any interval";
        return;
    }
    it--;
    pair<int,int> current= *it;
    if(current.first>=x && x<=current.second){ 
        cout<<"Yes, it is present, in interval: "<<current.first<<" - "<<current.second<<endl;
    }
    else{
        cout<<"It is not present in any interval";
    }
}

int main()
{
    vectorDemo();
    setDemo();
    mapDemo();
    PowerofSTL();
    return 0;
}