#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define PI 3.14159265
using namespace std;
typedef struct point{
	int x;
	int y;
}POINT;
bool inRange(POINT *p,POINT *l,POINT *r){
	int x_r = max(l->x,r->x);
	int x_l = min(l->x,r->x);
	int y_r = max(l->y,r->y);
	int y_l = min(l->y,r->y);
	if((p->x) >= x_l && (p->x)<=x_r && (p->y) >= y_l && (p->y)<=y_r){
		return true;
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int x1,y1,r1,x2,y2,r2;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		int j=x2-x1;
		if(j==0){
			j=1;
		}
		double ta = (y2-y1)/j*1.0;
		double ang = atan(ta);
		if(j==1){
			ang=PI/2;
		}
		//cout<<ang<<endl;
		double si = sin(ang);
		double co = cos(ang);
		POINT *p1 = new POINT;
		POINT *p2 = new POINT;
		POINT *p3 = new POINT;
		POINT *p4 = new POINT;
		p1->x=x1-(r1*co);
		p1->y=y1-(r1*si);
		p2->x=x1+(r1*co);
		p2->y=y1+(r1*si);
		p3->x=x2-(r2*co);
		p3->y=y2-(r2*si);
		p4->x=x2+(r2*co);
		p4->y=y2+(r2*si);
		if(!inRange(p1,p3,p4)){
			cout<<"YES"<<endl;
			cout<<p1->x<<" "<<p1->y<<endl;
		}
		else if(!inRange(p2,p3,p4)){
			cout<<"YES"<<endl;
			cout<<p2->x<<" "<<p2->y<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}
	return 0;
}