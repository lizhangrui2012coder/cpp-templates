#include <bits/stdc++.h>
using namespace std;
int main(){
	//找第一个大于等于x的位置 
	int n;
	cin>>n; 
	int l = 0, r = n; 
	while (l < r) {
    	int mid = l + (r - l) / 2; 
    	if (check(mid)) { //单独写 
        	r = mid; 
    	} 
		else {
        	l = mid + 1;
    	}
	}
	return 0;
} 
