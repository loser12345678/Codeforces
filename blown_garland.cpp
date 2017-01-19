#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	vector<char> v;
	v.push_back('B');
	v.push_back('G');
	v.push_back('R');
	v.push_back('Y');
	do{
		bool flag=true;
		map<char,int> m;
		for(int i=0;i<n;i++){
			if(s[i]=='!'){
				m[v[ i%4 ]]++;
			}
			else if(s[i]!=v[ i%4 ]){
				flag=false;
			}
		}
		if(flag==true){
			cout<< m['R'] <<" " << m['B'] <<" "<< m['Y'] <<" " << m['G' ] <<"\n";
			return 0;
		}
	}while(next_permutation(v.begin(),v.end()));
}
