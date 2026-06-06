#include <bits/stdc++.h>
using namespace std;
long long a,b,p,c;
int main(){
	cin>>a>>b>>p; 
	c=b;
	long long base=a;
	long long res=1;
	while(b>0){
		if(b&1){
			res=res*base%p;
		}
		base=base*base%p;
		b/=2;
	}
	cout<<a<<'^'<<c<<' '<<"mod"<<' '<<p<<'='<<res;
	return 0;
} 
