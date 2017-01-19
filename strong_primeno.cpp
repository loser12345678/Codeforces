#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll MaxVal=1e18+7;
class StrongPrimePower{
	public:
	ll f(ll a,ll b, ll n){
		ll ans=1;
		for(int i=1;i<=b;i++){
			ans*=a;
			if(ans>MaxVal)	return -1;
		}
		return ans;
	}
	vector<int> baseAndExponent(string s){
		vector<int> ans;
		long long int n=0;
		int si=s.length();
		for(int i=0;i<si;i++)	n=(n*10)+(s[i]-'0');
		for(int i=2;i<=63;i++){
			ll l=2,r=1e9;
			while(l<=r){
				ll mid=(l+r)/2;
				ll temp=f(mid,i,n);
				if(temp==n){
					ll temp1=sqrtl(mid);
					int flag=0;
					for(int j=2;j<=temp1;j++)	if(mid%j==0)	{ flag=1;break;}
					if(flag)	break;
					ans.push_back(mid);ans.push_back(i);return ans;
				}
				else if(temp==-1){
					r=mid-1;
				}
				else if(temp<n){
					l=mid+1;
				}
				else{
					r=mid-1;
				}
			}
		}
		return ans;
	}
};
int main(){
	StrongPrimePower s;
	vector<int> ans = s.baseAndExponent("64004320097200729");
	int si=ans.size();
	for(int i=0;i<si;i++)	cout<<ans[i]<<" ";
}
