#include <bits/stdc++.h>
using namespace std;
//字符串对比大小 
bool small(const vector<int>& x,const vector<int>& y){
  if(x.size()!=y.size())
    return x.size()<y.size();
  for(int i=max(x.size(),y.size())-1;i>=0;i--){
    if(x[i]<y[i])
      	return true;
    if(x[i]>y[i])
    	return false;
  }
  return false;

}



vector<int> zh(string s) {
    vector<int> res;
    for (int i = s.size() - 1; i >= 0; i--){
        res.push_back(s[i] - '0');
    }
    return res;
}
void print(const vector<int> &res){
	for(int i=res.size()-1;i>=0;i--){
		cout<<res[i];
	}
	cout<<endl;
	return;
}

//相加 
vector<int> add(const vector<int> &a, const vector<int>& b) {
    vector<int> res;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size() || t; i++) {
        if (i < a.size()) 
			t += a[i];
        if (i < b.size()) 
			t += b[i];
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}
//减法 
vector<int> minusx(const vector<int> &a,const vector<int>& b){
  	vector<int> res;
  	int bo=0; 
  	for(int i=0;i<a.size();i++){
    	int diff=a[i];
    	diff-=bo;
    	if(i<b.size())
    		diff-=b[i];
    	if(diff<0){
    		bo=1;
    		diff+=10;
		}
		else
			bo=0;
			res.push_back(diff);
  	}
  	while(res.size()>1&&res.back()==0){
  		res.pop_back();	
	}
  	return res;
}

//乘法  大数*大数 
vector<int> timex(const vector<int> &a,const vector<int>& b){
	vector<int> res(a.size()+b.size(),0);
  	for(int i=0;i<a.size();i++){
    	for(int j=0;j<b.size();j++){
      		res[i+j]+=(a[i])*(b[j]);
    	}	
  	}
  	for(int i=0;i<res.size()-1;i++){
    	res[i+1]+=res[i]/10;
    	res[i]%=10;
  	}
  	while(res.size()>1&&res.back()==0)
    	res.pop_back();
  	return res;
}
//乘法 大数*小数 
vector<int> timex_s(const vector<int> &a,const int b){
	vector<int> res;
	int ca=0;
  	for(int i=0;i<a.size()||ca;i++){
  		int pro=ca;
  		if(i<a.size())
      		pro+=a[i]*b;
		res.push_back(pro%10);
  		ca=pro/10;	
  	}
  	
  	while(res.size()>1&&res.back()==0)
    	res.pop_back();
  	return res;
}

//除法 
vector <int> dividex(const vector<int>& a,const vector<int> &b){
  	if(small(a,b))
  		return {0};
  	vector<int> qu;
  	vector<int> re;
  	for (int i=a.size()-1;i>=0; i--) {
  		int carry=0;
        for (int j=0;j<re.size(); j++) {
            int prod=re[j]*10+carry;
            re[j]=prod%10;
            carry=prod/10;
        }
        while (carry) {
            re.push_back(carry%10);
            carry/=10;
        }
        if (re.empty()) {
    		re.push_back(0);
		}
        re[0]+=a[i];
        carry=0;
        for (int j=0; j<re.size();j++) {
            int sum = re[j]+carry;
            re[j]=sum%10;
            carry=sum/10;
        }
        while(carry) {
            re.push_back(carry);
            carry=0;
        }
		int q=0;
		for(int d=9;d>=0;d--){
			vector<int> prod=timex_s(b,d);
			if(!small(re,prod)){
				q=d;
				re=minusx(re,prod);
				break;
			}
		}
		qu.push_back(q);
	}
	reverse(qu.begin(),qu.end());
	while(qu.size()>1&&qu.back()==0){
		qu.pop_back();
	}
	
	return qu;
}
//取模 
vector<int> qumo(const vector<int>& a, const vector<int>& b) {
    vector<int> qu = dividex(a, b);
    vector<int> prod = timex(qu, b);
    vector<int> re = minusx(a, prod);
    return re;
}
int main(){
	//加法 
	string a,b;
	cin>>a>>b;
	vector<int> sum=add(zh(a),zh(b));
	print (sum);
	//减法 
	vector<int> va = zh(a);
	vector<int> vb = zh(b);
	if (small(va, vb)) {
    	cout << "-";
    	sum = minusx(vb, va);
    	print(sum);
	} else {
    	sum = minusx(va, vb);
    	print(sum);
	}
	//乘法 
	sum=timex(zh(a),zh(b));
	print(sum);
	//除法 
	sum=dividex(zh(a),zh(b));
	print(sum);
	//取模
	sum=qumo(zh(a),zh(b));
	print(sum);
	return 0;
}
