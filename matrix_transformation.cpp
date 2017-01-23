#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> A,B,C;
vector<ll> points;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		bool flag=true;
		cin>>n>>m;
		A.clear();B.clear();C.clear();points.clear();
		A.resize(n);B.resize(n);C.resize(n);
		for(int i=0;i<n;i++){
			A[i].resize(m);
			B[i].resize(m);
			C[i].resize(m);
		}	
		for(int i=0;i<n;i++)	for(int j=0;j<m;j++)	cin>>A[i][j];
		for(int i=0;i<n;i++)	for(int j=0;j<m;j++){	cin>>B[i][j];	C[i][j]=A[i][j]-B[i][j];}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ll x=C[i][j]-C[i][0];
				ll y=C[0][j]-C[0][0];
				if(x!=y){
					flag=false;
					break;
				}		
			}
		}
		if(flag==false){
			cout<<"-1\n";
		}
		else{
			for(int i=0;i<n;i++)	points.push_back(C[i][0]-C[0][0]);
			for(int i=0;i<m;i++)	points.push_back(C[0][i]);
			sort(points.begin(),points.end());
			int si=points.size();
			ll temp=0,ans=0;
			if(si%2!=0){
				temp=points [ si/2 ] ;
			}	
			else{
				int t=si/2;
			 	temp=points[t];
				if((t+1)<si){
					temp=(temp+points[t+1])/2;
				}
			}
			for(int i=0;i<si;i++)	ans+=(abs(points[i]-temp));
			cout<<ans<<"\n";
		}
                                                                                    
	}
}
