/*
643. ���������ƽ���� I
���� n ���������ҳ�ƽ��������ҳ���Ϊ k �����������飬����������ƽ������



ʾ����

���룺[1,12,-5,-6,50,3], k = 4
�����12.75
���ͣ����ƽ���� (12-5-6+50)/4 = 51/4 = 12.75
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

//�Լ�д�ľ��Ǳ�����������
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
