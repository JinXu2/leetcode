/*
888. 公平的糖果棒交换
爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 根糖果棒的大小，B[j] 是鲍勃拥有的第 j 根糖果棒的大小。

因为他们是朋友，所以他们想交换一根糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。



示例 1：

输入：A = [1,1], B = [2,2]
输出：[1,2]
*/


//数组和问题 经典哈希算法
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA=accumulate(A.begin(),A.end(),0);
        int sumB=accumulate(B.begin(),B.end(),0);
        int delta=(sumA-sumB)/2;
        unordered_set<int> rec(A.begin(),A.end());
        vector<int> ans;
        for(auto&y :B)
        {
            int x=y+delta;
            if(rec.count(x))
            {
                ans=vector<int>{x,y};
                break;
            }
        }
        return ans;
    }
};

//其他做法 看看他俩相差多少 找到这两个糖果  相差 diff/2
