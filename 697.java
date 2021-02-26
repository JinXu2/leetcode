/*697. ����Ķ�
����һ���ǿ���ֻ�����Ǹ������������� nums������ĶȵĶ�����ָ��������һԪ�س���Ƶ�������ֵ��

����������� nums ���ҵ��� nums ӵ����ͬ��С�Ķȵ�������������飬�����䳤�ȡ�



ʾ�� 1��

���룺[1, 2, 2, 3, 1]
�����2
���ͣ�
��������Ķ���2����ΪԪ��1��2�ĳ���Ƶ����󣬾�Ϊ2.
��������������ӵ����ͬ�ȵ���������ʾ:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
�������������[2, 2]�ĳ���Ϊ2�����Է���2.
*/


//����ΪJava����
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


//ֻ����һ�εĻ� ��Ҫ��¼ÿ��Ԫ�ص�һ�γ��ֵ�λ�ã������ڳ����˼���
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

