/*
989. ������ʽ�������ӷ�
���ڷǸ����� X ���ԣ�X ��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����顣���磬��� X = 1231����ô��������ʽΪ [1,2,3,1]��

�����Ǹ����� X ��������ʽ A���������� X+K ��������ʽ��



ʾ�� 1��

���룺A = [1,2,0,0], K = 34
�����[1,2,3,4]
���ͣ�1200 + 34 = 1234
*/



class Solution{
public:
    //��ķ������� Ҫô����ת���������֮���ٱ�����飬�����������������һλλ��ӣ�����ÿλ���Ľ�λ
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
        //���ʣ�µ�
        for( ;K>0;K/=10)
        {
            res.push_back(K%10);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    //�߼�һ����뷨 ����һλλ�� ȫ���Ӹ����һλ
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



