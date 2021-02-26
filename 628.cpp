/*
628. �����������˻�
����һ���������飬���������ҳ�����������ɵ����˻������������˻���

ʾ�� 1:

����: [1,2,3]
���: 6
*/
//����Ŀ�϶����뵽�ܼ򵥵� ���� ����ע������и���������Ҫ�ȽϾ���ֵ

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);

    }
};

//�����ӶȱȽϸߣ���ʵֻҪ����������־ͺ� ������������С������ һ������ɨ��Ϳ�����

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
