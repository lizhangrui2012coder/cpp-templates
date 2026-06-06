#include <bits/stdc++.h>
using namespace std;
double check(double x){
	//函数
}
int main(){
	//小数二分 
	double l = 0.0, r = 100000.0; // 根据题目数据范围设定
	while (r - l > 1e-7) { // 精度通常比题目要求高 2 位
    	double mid = l + (r - l) / 2;
    	if (check(mid)) {
        	r = mid; // 或者 l = mid，取决于单调性
    	} 
		else {
        	l = mid;
		}
	} 
	return 0;
} 
