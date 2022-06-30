#include <bits/stdc++.h>

using namespace std;
struct Point{
   long  x,y;
}p0;

Point nextToStkTop(stack<Point> &S){
    Point p=S.top();
    S.pop();
    Point res=S.top();
    S.push(p);
    return res;
}

// void swap(Point &a, Point &b){
//     Point temp=a;
//     a=b;
//     b=temp;
// }

int orientation(Point p, Point q, Point r){
   long  value=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);
    return value;
}

long long  disSq(Point a, Point b){
    return (b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x);
}

    int compare(const void *vp1, const void* vp2){
    Point* p1=(Point*)vp1;
    Point* p2=(Point*)vp2;
    long o=orientation(p0,*p1,*p2);
    if(o==0){
        return (disSq(p0,*p1)>disSq(p0,*p2))? 1:-1;
    }
    else{
        return (o>0) ? 1:-1 ;
    }

}

long int convexHull(vector<Point> points,int n){
   long l=0;
    for(int i=0;i<n;i++){
        if(points[i].y<points[l].y){
            l=i;
        }
        if(points[i].y==points[l].y){
            if(points[i].x<points[l].x){
                l=i;
            }
        }
    }
    swap(points[0],points[l]);

    p0=points[0];

    qsort(&points[1],n-1,sizeof(Point),compare);
   
   long m=1;
    for(int i=1;i<n-1;i++){
        
        while(i<n-1 && orientation(p0,points[i],points[i+1])==0){
            i++;
        }
        points[m++]=points[i];
    }

    stack<Point> stk;
    stk.push(p0);
    stk.push(points[1]);
    stk.push(points[2]);
    for(int i=3;i<m;i++){
        if(!stk.empty() && orientation(nextToStkTop(stk),stk.top(),points[i])>0){   //cw=right(+)  acw=left(-)
            stk.pop();
        }  
        stk.push(points[i]);
    }
    long count=0;
    while(!stk.empty()){
        Point p=stk.top();
        stk.pop();
        count++;
        //cout<<"("<<p.x<<","<<p.y<<")"<<endl;
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
       long n,r;
        cin>>n>>r;
        vector<Point> points;
        //points.reserve(n);
        for(int i=0;i<n;i++){
           long  x,y;
            cin>>x>>y;
            points.push_back({x,y});
        }
       long ct=convexHull(points,n);
        if(ct>r){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
        
    }
    return 0;
}