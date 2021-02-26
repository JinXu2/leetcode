/*
480. 滑动窗口中位数
中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

例如：

[2,3,4]，中位数是 3
[2,3]，中位数是 (2 + 3) / 2 = 2.5
给你一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。



示例：

给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。
*/

//自己创建数据结构

class  DualHeap{
private:
    //大根堆 默认大根堆的
    priority_queue<int> small;
    //小根堆 要用greater
    priority_queue<int,vector<int>,greater<int>> large;
    //哈希表，记录延迟删除元素，key为元素，value为需要删除的次数
    unordered_map<int,int> delayed;

    int k;
    int smallSize,largeSize;

public:


};





//红黑树版本的 看不懂的
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
public:
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> t;
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        queue<pair<int, int>> q;
        vector<double> ans;
        for(int i = 0; i < nums.size(); ++i) {
            q.push({nums[i], i});
            t.insert({nums[i], i});
            if(q.size() >= k) {
                long x = (*t.find_by_order(k / 2)).first;
                long y = (*t.find_by_order((k - 1) / 2)).first;
                ans.push_back((x + y) / 2.0);
                t.erase(q.front());
                q.pop();
            }
        }
        return ans;
    }
};

