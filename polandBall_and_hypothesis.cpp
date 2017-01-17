#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isPrime(ll n){
	ll temp=sqrt(n);
	for(int i=2;i<=temp;i++){
		if(n%i==0)	return false;
	}
	return true;
}

int main(){
	ll n;
	cin>>n;
	for(ll i=1;i<=1e3;i++){
		ll x=(n*i)+1;
		if(!isPrime(x)){
			cout<<i<<"\n";
			return 0;
		}
	}
}
