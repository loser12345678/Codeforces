#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int maxn=111;
int a[maxn];
int b[maxn];
vector<ll> v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=-1;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==-1){
			int j=i,t=0;
			while(1){
				b[j]=1;
				j=a[j];
				if(b[j]==1)	break;
				t++;
				
			}
			if(j!=i){
				cout<<"-1\n";return 0;
			}
			else{
				t++;
				if(t%2==0){
					v.push_back(t/2);
				}
				else{
					v.push_back(t);
				}
			}
		}
	}
	int si=v.size();
	ll t=v[0];
	for(int i=1;i<si;i++){
		ll temp=v[i]*t;
		ll temp1=__gcd(v[i],t);
		t=(temp/temp1);
	}
	cout<<t<<"\n";
	
}
