/*
628. 三个数的最大乘积
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1,2,3]
输出: 6
*/
//这题目肯定会想到很简单的 排序 但是注意的是有负数，所以要比较绝对值

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);

    }
};

//排序复杂度比较高，其实只要关心五个数字就好 最大的三个和最小的两个 一次线性扫描就可以了

int maximumProduct(vector<int>& nums) {
    int min1=INT_MAX;
    int min2=INT_MAX;
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;

    for(int x:nums)
    {
        if(x<min1){
            min2=min1;
            min1=x;
        }else if(x<min2)
        {
            min2=x;
        }

        if(x>max1)
        {
            max3=max2;
            max2=max1;
            max1=x;
        }else if(x>max2)
        {
            max3=max2;
            max2=x;
        }else if(x>max3)
        {
            max3=x;
        }
    }
    return max(min1*min2*max1,max1*max2*max3);
}
