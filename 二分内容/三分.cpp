#include <bits/stdc++.h>
using namespace std;
int min_x,max_x;//范围
double f(double x){
	//函数
}
int main(){
	//三分
	double l = min_x, r = max_x;

	for (int i = 0; i < 100; i++) {//用while效果一样 
    	double m1 = l + (r - l) / 3;
    	double m2 = r - (r - l) / 3;
    	//最小 
    	if (f(m1) < f(m2)) {
        	// m1 处更低，最小值在 [l, m2] 之间，舍弃右边
        	r = m2;
    	} 
		else {
        	// m2 处更低（或相等），最小值在 [m1, r] 之间，舍弃左边
        	l = m1;
    	}
    	//最大 
    	//if (f(m1) > f(m2)) {
    		// m1 处更高，最大值在 [l, m2] 之间
    		//r = m2;
		//} else {
    		// m2 处更高，最大值在 [m1, r] 之间
    		//l = m1;
		//}
	}

// 最终 l 和 r 非常接近，任选一个计算即可
	printf("%.6f\n", f(l));
	return 0;

