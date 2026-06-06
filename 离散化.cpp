#include <bits/stdc++.h> 
using namespace std;

vector<int> nums; // 存储所有出现过的坐标

void add_val(int x) {
    nums.push_back(x);
}

// 2. 初始化（排序 + 去重）
void init_discrete() {
    sort(nums.begin(), nums.end());
    // unique 返回去重后末尾的迭代器，erase 删除后面的垃圾
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
}

// 3. 查询映射后的 ID (从 1 开始)
int get_id(int x) {
    // lower_bound 返回第一个 >= x 的位置
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
}
int main(){
	return 0;
}
