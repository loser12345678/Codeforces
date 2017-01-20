#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7,maxn1=2e6+7;
int a[maxn],b[maxn],st[maxn1],ans[maxn];
void upd(int ss,int se,int i,int si,int val){
	if(i<ss || i >se)	return;
	st[si]=max(st[si],val);
	if(se!=ss){
		int mid=(ss+se)/2;
		upd(ss,mid,i,(2*si)+1,val);
		upd(mid+1,se,i,(2*si)+2,val);
	}
}
int query(int ss,int se,int qs,int qe,int si){
	if(qs<=ss && qe>=se){
		return st[si];
	}
	if(se<qs || ss>qe)	return 0;
	int mid=(ss+se)/2;
	return max(query(ss,mid,qs,qe,(2*si)+1),query(mid+1,se,qs,qe,(2*si)+2));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	}
	ans[n]=-1;
	upd(1,n,a[n],1,n);
	for(int i=n-1;i>=1;i--){
		int ans1=query(1,n,1,a[i]-1,1);
		if(ans1==0){
			ans[i]=-1;
		}
		else{
			ans[i] = ans1-i-1;
		}
		upd(1,n,a[i],1,i);	
	}
	for(int i=1;i<=n;i++)	cout<<ans[i]<<" ";
	
}
