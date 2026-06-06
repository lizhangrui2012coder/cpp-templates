#include <bits/stdc++.h>
using namespace std;
double check(double x){
	//函数
}
int main(){
	//找最后一个大于等于x的位置 
	int n;
	cin>>n;
	int l = 0, r = n; 
	while (l < r) {
    	int mid = l + (r - l + 1) / 2; // 这里要 +1，向上取整，防止死循环
    	if (check(mid)) {
        	l = mid;
    	}
		else {
        	r = mid - 1;
    	}
	}

	return 0;
} 
