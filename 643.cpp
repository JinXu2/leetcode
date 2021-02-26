/*
643. 子数组最大平均数 I
给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。



示例：

输入：[1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=nums[k];
        }
        int maxsum=sum;
        for(int i=k;i<n;i++)
        {
            sum=sum-nums[i-k]+nums[i];
            maxsum=max(maxsum,sum);
        }
        return static_cast<double>(maxsum)/k;
    }
};

//自己写的就是笨蛋滑动窗口
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len=nums.size();
        int left=0;
        int right=k-1;
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        int maxsum=sum;
        while(right<len&&left<len-k)
        {
            sum-=nums[left];
            left++;
            right++;
            sum+=nums[right];
            maxsum=max(maxsum,sum);
        }
        return (double)maxsum/k;
    }
};
