#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int n;
	int a[10];
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)	cin>>a[i];
		for(int i=1;i<=n;i++)	cout<<a[i];
		cout<<"\n";
	}
}
