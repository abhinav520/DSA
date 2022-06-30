#include <bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;
}p0;

Point nextToStkTop(stack<Point> &S){
    Point p=S.top();
    S.pop();
    Point res=S.top();
    S.push(p);
    return res;
}

void swap(Point &a, Point &b){
    Point temp=a;
    a=b;
    b=temp;
}

int orientation(Point p, Point q, Point r){
    int value=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);
    return value;
}

int disSq(Point a, Point b){
    return (b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x);
}

int compare(const void *vp1, const void* vp2){
    Point* p1=(Point*)vp1;
    Point* p2=(Point*)vp2;
    int o=orientation(p0,*p1,*p2);
    if(o==0){
        return (disSq(p0,*p1)>disSq(p0,*p2))? 1:-1;
    }
    else{
        return (o>0) ? 1:-1 ;
    }

}

void convexHull(Point points[],int n){
    int l=0;
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
    // for(int i=0;i<n;i++){
    //     cout<<points[i].x<<","<<points[i].y<<endl;
    // }
    // cout<<"*******"<<endl;

    int m=1;
    for(int i=1;i<n-1;i++){
        
        while(i<n-1 && orientation(p0,points[i],points[i+1])==0){
            i++;
        }
        points[m++]=points[i];
    }
    // for(int i=0;i<m;i++){
    //     cout<<points[i].x<<","<<points[i].y<<endl;
    // }
    // cout<<"*******"<<endl;
    
    if(m<3) return;

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
    while(!stk.empty()){
        Point p=stk.top();
        stk.pop();
        cout<<"("<<p.x<<","<<p.y<<")"<<endl;
    }


}


int main()
{
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},{0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}