#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;	
	cin>>n;
	long long int ans=0,a[n],temp=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		temp=max(temp,a[i]);
	}
	for(int i=0;i<n;i++){
		ans+=(temp-a[i]);
	}
	cout<<ans<<"\n";
}
