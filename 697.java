/*697. 数组的度
给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。



示例 1：

输入：[1, 2, 2, 3, 1]
输出：2
解释：
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
*/


//以下为Java语言
class Solution {
    public int getDegree(int[] nums){
        Map<Integer,Integer> map = new HashMap<>();
        int res=0;
        for(int i:nums)
        {
            map.put(i,map.getOrDefault(i,0)+1);
            res=Math.max(res,map.get(i));
        }
        return res;
    }

    public int findShortestSubArray(int[] nums) {
        int l=0,r=0,len=nums.length,res=len+1;
        Map<Integer,Integer> map = new HashMap<>();
        int maxDegree=getDegree(nums);
        while(r<len)
        {
            map.put(nums[r],map.getOrDefault(nums[r],0)+1);
            r++;
            while(map.get(nums[r-1])==maxDegeree)
            {
                map.put(nums[l],map.get(nums[l])-1);
                res=Math.min(res,r-l);
                l++;
            }
        }
        return res;
    }
}


//只遍历一次的话 需要记录每个元素第一次出现的位置，和现在出现了几次
public int findShortestSubArray(int[] nums) {
    int len=nums.length,maxCount=0,minWindow=0;
    Map<Integer,int[]> map = new HashMap<>();
    for(int i=0;i<len;i++)
    {
        int []pair = map.get(nums[i]);
        if(pair==null)
        {
            pair = new int[]{i,1};
            map.put(nums[i],pair);
        }else
        {
            pair[1]++;
        }
        if(pair[1]>maxCount)
        {
            maxCount=pair[1];
            minWindow = i-pair[0]+1;
        }else if(pair[1]==maxCount)
        {
            minWindow = Math.min(minWindow,i-pair[0]+1);
        }
    }
    return minWindow;
}

