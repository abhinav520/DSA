#include <iostream>
#include <vector>
using namespace std;

struct point{
    int x,y;
};

int dotProduct(point p, point q, point r){
    int val=(r.y-q.y)*(q.x-p.x)-(q.y-p.y)*(r.x-q.x);
    return val;
}

bool onSegment(point p,point q, point r){
    // point q lies on line segment 'pr'
    return(q.x<=max(p.x,r.x) && q.x>=min(p.x,r.x) && q.y<=max(r.y,p.y) && q.y>=min(r.y,p.y));
}

void convexHull(point points[], int n){
    if(n<3) return;

    vector<point> hull;
    int l=0;
    for(int i=0;i<n;i++){
        if(points[i].x<points[l].x){
            l=i;
        }
        else if(points[i].x==points[l].x){
            if(points[i].y<points[l].y){
                l=i;
            }
        }
    }

    int p=l,q;
    do{
        hull.push_back(points[p]);
        q=(p+1)%n;
        for(int i=0;i<n && i!=p;i++){
            if(dotProduct(points[p],points[i],points[q])>0){
                q=i;
            }
            else if(dotProduct(points[p],points[i],points[q])==0 && onSegment(points[p],points[q],points[i])){
                q=i;
            }
        }  
        p=q;
    }while(p!=l);

    for(int i=0;i<hull.size();i++){
        cout<<"("<<hull[i].x<<","<<hull[i].y<<")\n";
    }
}

int main() 
{ 
	point points[] = {{2, 2}, {4, 3}, {5, 4},{0, 3}, {0, 2}, {0, 0}, {2, 1}, {2, 0}, {4, 0}}; 
	int n = sizeof(points)/sizeof(points[0]); 
	convexHull(points, n); 
	return 0; 
} 