#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
#define mp make_pair
#define F first
#define S second
using namespace std;
pair<int,int> seg(vector<int> a){
	int l=-1,r=-2;
	int curr_l,curr_r;
	for(int i=0;i<(int)a.size();i++){
		//cout<<i<<endl;
		if(a[i]==0){
			curr_l = i;
			while(i<(int)a.size() && a[i]==0){
				i++;
			}
			i--;
			curr_r = i;
			if(curr_r-curr_l>r-l){
				r = curr_r;
				l = curr_l;
			}	
		}		
	}
	return mp(l,r);
}
bool cmp(pair<int,pair<int,int> > p1, pair<int,pair<int,int> > p2){
	if(p1.first>p2.first){
			return false;
	}
	if(p1.first==p2.first){
		if(p1.second.first<p2.second.first){
				return false;
		}
		if(p1.second.first==p2.second.first){
			if(p1.second.second<=p2.second.second){return false;}
			return true;
		}
		return true;
	}
	return true;
}
void fill_seg(vector<int> &a){
	int n = a.size();
	priority_queue< pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > > ,function<bool(pair<int,pair<int,int> >, pair<int,pair<int,int> >)> > q(cmp);
	q.push(mp(n,mp(0,n-1)));
	int count=1;
	while(!q.empty()){
		pair<int,int> segm = q.top().second;
		q.pop();
		if(segm.first>segm.second){
			continue;
		}
		int mid = segm.first + (segm.second-segm.first)/2;
		a[mid] = count;
		count++;
		if(mid-segm.first>=segm.second-mid){
			//fill left
			q.push(mp(mid-segm.first,mp(segm.first,mid-1)));
			q.push(mp(segm.second-mid,mp(mid+1,segm.second)));
		}
		else{
			q.push(mp(segm.second-mid,mp(mid+1,segm.second)));
			q.push(mp(mid-segm.first,mp(segm.first,mid-1)));
		}	
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n,0);
		
		//Fo(i,1,n+1){
			//pair<int,int> segment = seg(a);
			//int l = segment.first+1;
			//int r = segment.second+1;
//cout<<l<<r<<endl;
			//if(l<0 || r<0){
				//break;
			//}
			//if((r-l+1)%2){
				//a[((l+r)/2)-1] = i;
			//}
			//else{
				//a[((l+r-1)/2)-1]= i;
			//}
		//}
		fill_seg(a);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
