/*
989. 数组形式的整数加法
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。

给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。



示例 1：

输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
*/



class Solution{
public:
    //最笨的方法就是 要么数组转成整数相加之后再变成数组，或者是整数变成数组一位位相加，考虑每位数的进位
    vector<int> addToArrayForm(vector<int> &A,int K)
    {
        vector<int> res;
        int n=A.size();
        for(int i=n-1;i>=0;i--)
        {
            int sum=A[i]+K%10;
            K/=10;
            if(sum>=10)
            {
                K++;
                sum-=10;
            }
            res.push_back(sum);
        }
        //最后剩下的
        for( ;K>0;K/=10)
        {
            res.push_back(K%10);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    //高级一点的想法 不用一位位算 全部加给最后一位
    vector<int> addToArrayForm(vector<int> &A,int K)
    {
        vector<int> res;
        int n=A.size();
        for(int i=n-1;i>=0||K>0;i--,K/=10)
        {
            if(i>=0)
            {
                K+=A[i];
            }
            res.push_back(K%10);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};



