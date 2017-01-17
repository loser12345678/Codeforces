#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<string> p1;
	int n,m;	
	cin>>n>>m;
	string t;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>t;
		p1.insert(t);
	}
	for(int i=1;i<=m;i++){
		cin>>t;
		if(p1.find(t)!=p1.end()){
			cnt++;
		}
	}
	int x=n-cnt,y=m-cnt;
	if(cnt%2==0){
		if(x>y){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	else{
		if(x>=y){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
