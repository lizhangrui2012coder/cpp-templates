#include <bits/stdc++.h>
using namespace std;

map<int, int> val_to_id; // 键：原始大数值，值：分配的小 ID
int id_counter = 0;      // 当前分配到的最大 ID

int get_id_dynamic(int x) {
    // 如果 x 还没出现过
    if (val_to_id.find(x) == val_to_id.end()) {
        id_counter++;          // 计数器 +1
        val_to_id[x] = id_counter; // 记录映射
    }
    return val_to_id[x];       // 返回 ID
}
int main(){
	return 0;
}
