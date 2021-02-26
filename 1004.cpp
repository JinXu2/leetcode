/*
1004. 最大连续1的个数 III
给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

返回仅包含 1 的最长（连续）子数组的长度。



示例 1：

输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
*/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left=0;
        int right=0;
        int len=A.size();
        int countzero=0;
        int res=0;
        while(right<len)
        {
            if(A[right]==0)
            {
                countzero++;
            }
            right++;
            while(zerocount>K)
            {
                if(A[left]==0)
                {
                    zerocount--;
                }
                left++;
            }
            res=max(res,r-l);
        }
        return res;
    }
};

//无敌简洁版本
int longestOnes(vector<int>&A,int K)
{
    int l=0,r=0;
    while(r<A.size())
    {
        K-=1-A[r++];
        if(K<0)
        {
            K+=1-A[l++];
        }
    }
    return r-l;
}
