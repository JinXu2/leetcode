

//前缀和
class Solution{
public:
    int pivotIndex(vector<int>&nums)
    {
        int n=nums.size();
        vector<int> s(n+1,0);
        for(int i=1;i<=n;i++)
        {
            s[i]=s[i-1]+nums[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]==s[n]-s[i])
            {
                return i-1;
            }
        }
        return -1;
    }
};

//官方更巧妙一点的算法
class Solution{
public:
    int pivotIndex(vector<int>& nums)
    {
        int total=accumulate(nums.begin(),nums.end(),0);
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if( 2*sum + nums[i]==total)
            {
                return i;
            }
            sum+=nums[i];
        }
        return -1;
    }
};
