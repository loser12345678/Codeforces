#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
const int maxn=511;
ll a[maxn][maxn];
int n;	
ll f(int i){
	ll sum=0;
	for(int j=1;j<=n;j++)	sum+=a[i][j];
	return sum;
}
bool check(ll s){
	for(int i=1;i<=n;i++){	
		ll sum=0,sum1=0;
		for(int j=1;j<=n;j++){
			sum+=a[i][j];sum1+=a[j][i];
		} 
		if(sum!=s || sum1!=s)	return false;
	}
	ll sum=0,sum1=0;
	for(int i=1;i<=n;i++){
		sum+=a[i][i];
		sum1+=a[i][n-i+1];
	}
	return (s==sum) && (s==sum1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++)	cin>>a[i][j];
	if(n==1){
		if(a[1][1]!=0){
			cout<<"-1\n";return 0;
		}
		cout<<"1\n";
	}
	else if(n==2){
		int c=0,c1=0;
		for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++){
			if(a[i][j]==0)	c++;
			if(a[i][j]!=0){
				if(c1==0)	c1=a[i][j];
				else if(c1!=a[i][j]){
					cout<<"-1\n";return 0;
				}
			}
		}
		cout<<c1<<"\n";
	}
	else{
		ll req[n+1];
		for(int i=1;i<=n;i++)	req[i]=f(i);
		sort(req+1,req+n+1);	
		if(req[1]!=req[2] && req[2]==req[n]){
			for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++)	if(a[i][j]==0)	a[i][j]=req[2]-req[1];
			if(check(req[2])){
				cout<< req[2]-req[1] <<"\n";return 0;
			}		
			cout<<"-1\n";
		}
		else{
			cout<<"-1\n";
		}
	}
}
